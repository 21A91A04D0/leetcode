class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        int sm = 0;
        for(int i = 0 ; i < n ; i++)
        {
            sm +=nums[i];
        }
        int sm_n = (n * (n + 1)) / 2;
        map<int, int> mp;
        int rep = 0;
        for(auto it: nums)
        {
            mp[it]++;
            if(mp[it] == 2) {
                rep = it;
                break;
            }
        }
        int res = sm - rep;
        int res1 = sm_n - res;
        vector<int> A;
        A.push_back(rep);
        A.push_back(res1);
        return A;
    }
};