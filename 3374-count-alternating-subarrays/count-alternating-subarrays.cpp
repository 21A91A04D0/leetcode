class Solution {
public:
    long long countAlternatingSubarrays(vector<int>& nums) {
        int i = 0;
        long long ans = 0;
        int j = 0;
        while(i < nums.size() - 1) {
            if(nums[i] != nums[i + 1]) {
                i++;
            }
            else {
                // cout << i << " " << j << "->";
                int ind = i - j + 1;
                
                ans += ((ind * (ind - 1)) / 2);
                i++;
                j = i;
            }
        }
        long long ind1 = i - j + 1;
        // cout << i << " " << j;
        ans += ((ind1 * (ind1 - 1)) / 2);
        ans += nums.size();
        return ans;
    }
};