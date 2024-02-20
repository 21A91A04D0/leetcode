class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sm = 0;
        for(auto it : nums) {
            sm += it;
        }
        int n = nums.size();
        int ans = n * (n + 1) / 2;
        return ans - sm;
    }
};