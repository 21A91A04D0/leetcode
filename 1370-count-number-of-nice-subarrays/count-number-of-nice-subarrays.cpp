class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int prefix = 0;
        map<int, int> mp;
        mp[0] = 1;
        int n = nums.size(), res = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] % 2 == 1) {
                prefix += 1;
            }
            int ans = prefix - k;
            if(mp.find(ans) != mp.end()) {
                res += mp[ans];
            }
            mp[prefix]++;
        }
        return res;
    }
};