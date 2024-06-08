class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        map<int, int> mp;
        int prefix = 0;
        mp[0] = -1;
        for(int i = 0; i < nums.size(); i++) {
            prefix += nums[i];
            int ans = prefix % k;
            if(mp.find(ans) == mp.end()) {
                mp[ans] = i;
            }
            else if(i - mp[ans] >= 2) return true;
        }
        return false;
    }
};