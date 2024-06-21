class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int grumpy_total = 0;
        int n = grumpy.size();
        for(int i = 0 ; i < minutes; i++) {
            if(grumpy[i] == 1) {
                grumpy_total += customers[i];
            }
        }
        int res = grumpy_total;
        int j = 0;
        for(int i = minutes; i < n; i++) {
            if(grumpy[i] == 1) {
                grumpy_total += customers[i];
            }
            if(grumpy[j] == 1) {
                grumpy_total -= customers[j];
            }
            res = max(res,grumpy_total);
            j++;
        }
        for(int i = 0 ; i < n; i++) {
            if(grumpy[i] == 0) {
                res += customers[i];
            }
        }
        return res;
    }
};