class Solution {
public:
    void sortColors(vector<int>& nums) {
        for(int i = nums.size() - 1 ; i >= 0; i--) {
            for(int j = 1; j <= i ; j++) {
                if(nums[j] < nums[j - 1]) swap(nums[j], nums[j - 1]);
            }
        }
        
    }
};