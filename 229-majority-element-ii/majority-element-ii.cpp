class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // extended moore's voting algorithm
        int cnt1 = 0, cnt2 = 0, ele1, ele2, n = nums.size();
        for(int i = 0; i < n; i++) {
            if(cnt1 == 0 and nums[i] != ele2) {
                cnt1 = 1;
                ele1 = nums[i];
            }
            else if(cnt2 == 0 and nums[i] != ele1) {
                cnt2 = 1;
                ele2 = nums[i];
            }
            else if(nums[i] == ele1) cnt1++;
            else if( nums[i] == ele2) cnt2++;
            else {
                cnt1--;
                cnt2--;
            }
        }
        int c1 = 0, c2 = 0; 
        for(int i = 0; i < n; i++) {
            if(nums[i] == ele1) {
                c1++;
            }
            else if(nums[i] == ele2) c2++;
        }
        vector<int> ans;
        if(c1 > n / 3) ans.push_back(ele1);
        if(c2 > n / 3) ans.push_back(ele2);
        return ans;
    }
};