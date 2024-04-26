class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //moore's voting algorithm
        int ele;
        int cnt = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(cnt == 0) {
                ele = nums[i];
                cnt = 1;
            }
            else if(nums[i] == ele) cnt++;
            else cnt--;
        }
        int c = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == ele) c++;
        }
        if(c > (nums.size() / 2)) return ele;
        return -1;
    }
};