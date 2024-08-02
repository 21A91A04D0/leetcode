class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int window = 0;
        for(auto it : nums) {
            if(it == 1) window++;
        }
        int n = nums.size();
        int zeros = 0, mn = INT_MAX;
        for(int i = 0 ;i < 2 * n ; i++) {
            if(i < window && nums[i] == 0) {
                zeros++;
                if(i == window - 1) mn = min(mn, zeros);
            }
            if(i >= window) {
                if(nums[i % n] == 0) {
                    zeros++;
                }
                if(nums[(i - window) % n] == 0) {
                    zeros--;
                }
                mn = min(mn, zeros);
            }
        }
        return mn;
    }
};