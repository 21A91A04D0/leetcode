class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size(),ans = 0;
        
        vector<int> flip(n + 1, 0);
        if(nums[0] == 0) {
            ans++;
            flip[k] = -1;
            flip[0] = 1;
        }
        for(int i = 1 ; i <= n - k; i++) {
            int pre = flip[i - 1] + flip[i];
            flip[i] = pre;
            if(pre % 2 && nums[i] == 1) {
                flip[i]++;
                ans++;
                flip[i + k] = -1;
            }
            else if(pre % 2 == 0 and nums[i] == 0) {
                ans++;
                flip[i]++;
                flip[i + k] = -1;
            }
        }
        
        for(int i = n - k + 1; i < n ;i++) {
            int pref = flip[i - 1] + flip[i];
            flip[i] = pref;
            if(pref % 2 == 0 and nums[i] == 0) return -1;
            if(pref % 2 && nums[i] == 1) return -1;
        }
        return ans;
    }
};