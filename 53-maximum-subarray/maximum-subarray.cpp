class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int mx = INT_MIN;
        int sm = 0;
        for(int i = 0 ; i < nums.size() ; i++) {
            sm += nums[i];
            mx = max(mx, sm);
            if(sm < 0) sm = 0;
            
        }
        return mx;
    }
};