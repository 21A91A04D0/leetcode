class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for(int i = 0 ; i < nums.size() ; i+=3) {
            vector<int> sub;
            if(nums[i + 2] - nums[i] <= k) {
                sub.push_back(nums[i]);
                sub.push_back(nums[i + 1]);
                sub.push_back(nums[i + 2]);
                ans.push_back(sub);
            }
            else {
                return {};
            }
        }
        return ans;
    }
};