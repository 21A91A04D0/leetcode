class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        map<int, int> mp;
        for(auto it : nums) {
            mp[it]++;
        }
        nums.clear();
        for(auto it : mp) {
            nums.push_back(it.first);
        }
        sort(nums.begin(), nums.end());
        int i = 0;
        while(i < nums.size() and nums[i] <= 0) {
            i++;
        }
        int k = 1;
        while(i < nums.size() and nums[i] == k) {
            i++;
            k++;
        }
        return k;
    }
};