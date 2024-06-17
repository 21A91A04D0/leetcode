class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() <= 1) return 1;
        int i = 1,j = 1, cnt = 1;
        while(i < nums.size()) {
            if(nums[i] == nums[i - 1]) {
                i++;
            }
            else if(nums[i] != nums[i - 1]) {
                cnt++;
                nums[j] = nums[i];
                j++;
                i++;
            }
        }
        return cnt;
    }
};