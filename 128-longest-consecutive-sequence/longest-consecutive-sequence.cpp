class Solution {
public:
    int longestConsecutive(vector<int>& num) {
        set<int> st;
        for(auto it : num) st.insert(it);
        vector<int> nums;
        for(auto it : st) nums.push_back(it);
        if(nums.size() == 0) return 0;
        // sort(nums.begin(), nums.end());
        int mx = 0;
        int cnt = 1;
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] - nums[i - 1] == 1) cnt++;
            else {
                mx = max(mx, cnt);
                cnt = 1;
            }
        }
        mx = max(mx, cnt);
        return mx;
    }
};