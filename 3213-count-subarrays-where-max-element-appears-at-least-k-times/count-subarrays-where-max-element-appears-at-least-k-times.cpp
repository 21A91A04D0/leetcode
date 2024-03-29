class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int max_element = 0;
        for(auto it : nums) {
            if(it > max_element) max_element = it;
        }
        int max_count = 0;
        int i = 0;
        int j = 0;
        long long ans = 0;
        while(i < nums.size()) {
            if(nums[i] == max_element) max_count++;
            if(max_count == k) {
                while(max_count == k) {
                    ans += nums.size() - i;
                    if(nums[j] == max_element) max_count--;
                    j++;
                }
            }
            i++;
        }
        return ans;
    }
};