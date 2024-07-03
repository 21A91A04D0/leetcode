class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        if(n <= 4) return 0;
        int ans = INT_MAX;
        int right = n - 3 - 1;
        int left = 0;
        while(right < n) {
            ans = min(ans, nums[right] - nums[left]);
            right++;
            left++;
        }
        return ans;
    }
};