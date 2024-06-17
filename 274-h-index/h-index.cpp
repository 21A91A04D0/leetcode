class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int l = citations.size();
        int ele = 0;
        for(int i = 0; i < l; i++) {
            if(citations[i] >= l - i) {
                ele++;
            }
        }
        return ele;
    }
};