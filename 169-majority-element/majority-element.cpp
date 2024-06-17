class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ele, cnt = 0, n = nums.size();
        for(int i = 0; i < n; i++) {
            if(cnt == 0) {
                ele = nums[i];

                cnt = 1;
            }
            else if(ele == nums[i]) cnt++;
            else cnt --;
        }
        int count = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] == ele) count++;
        }
        if(count > n / 2) return ele;
        return -1;
    }
};