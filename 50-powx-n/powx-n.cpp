class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1;
        bool flag = true;
        if(n < 0) flag = false;
        n = abs(n);
        while(n > 0) {
            if(n % 2 == 0) {
                x = x * x;
                n /= 2;
            }
            else {
                ans *= x;
                n--;
            }
        }
        if(flag == false) return 1 / ans;
        return ans;
    }
};