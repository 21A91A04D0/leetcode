class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> neg;
        vector<int> pos;
        for(int i = 0 ; i < nums.size() ; i++) {
            if(nums[i] < 0) {
                neg.push_back(nums[i]);
            }
            else {
                pos.push_back(nums[i]);
            }
        }
        int i = 0;
        nums.clear();
        while(i < neg.size()) {
            nums.push_back(pos[i]);
            nums.push_back(neg[i]);
            i++;
        }
        return nums;
    }
};