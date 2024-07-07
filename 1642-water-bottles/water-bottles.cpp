class Solution {
public:
    int numWaterBottles(int n, int x) {
        int cnt = n;
        int empty = n;
        while(empty >= x) {
            cnt += (empty / x);
            
            empty = (empty % x) + (empty / x);
        }
        return cnt;
    }
};