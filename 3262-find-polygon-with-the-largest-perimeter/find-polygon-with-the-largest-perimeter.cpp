class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        long long prefix = nums[0] + nums[1];
        long long res = -1;
        for(int i = 2 ; i < nums.size() ; i++) {
            if(prefix > nums[i]) {
                res = prefix + nums[i];
            }
            prefix += nums[i];
        }
        return res;
    }
};