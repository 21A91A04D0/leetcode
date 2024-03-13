class Solution {
public:
    int pivotInteger(int n) {
        int nn = (n * (n + 1)) / 2;
        int left = 0;
        for(int i = 1 ; i <= n ; i++) {
            left += i;
            if(left == nn) return i;
            nn -= i;
        }
        return -1;
    }
};