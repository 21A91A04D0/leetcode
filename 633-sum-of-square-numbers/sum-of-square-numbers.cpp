class Solution {
public:
    bool judgeSquareSum(int c) {
        int left = 0;
        int right = sqrt(c);
        while(left <= right) {
            long long sq = pow(left, 2) + pow(right, 2);
            if(sq == c) {
                return true;
            }
            else if(sq < c) {
                left++;
            }
            else right--;
        }
        return false;
    }
};