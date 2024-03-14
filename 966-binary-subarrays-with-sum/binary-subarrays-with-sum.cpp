class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int cnt = 0;
        map<int, int> mp;
        mp[0] = 1;
        int prefix = 0;
        int i = 0;
        while(i < nums.size()) {
            prefix += nums[i];
            if(mp[prefix - goal] != 0) {
                cnt += mp[prefix - goal];
            }
            mp[prefix]++;
            i++;
        }
        return cnt;
    }
};