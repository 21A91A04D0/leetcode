class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int ind = -1;
        for(int i = 0 ; i < nums.size() - 1; i++) {
            if(nums[i] < nums[i + 1]) {
                ind = i;
            }
        }
        if(ind == -1) {
            reverse(nums.begin(), nums.end());
        }
        else {
            int gind = -1;
            for(int i = ind + 1; i < nums.size(); i++) {
                if(nums[i] > nums[ind]) {
                    gind = i;
                }
            }
            
            swap(nums[ind], nums[gind]);
            reverse(nums.begin() + ind + 1, nums.end());
        }
        
        

    }
};