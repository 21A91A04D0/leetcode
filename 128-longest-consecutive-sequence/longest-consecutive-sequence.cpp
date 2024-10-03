class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // optimal approach
        unordered_set<int> st;
        for(auto it : nums) st.insert(it);
        int mx = 1;
        if(nums.size() == 0) return 0;
        for(auto it: st) {
            if(st.find(it - 1) == st.end()) {
                int cnt = 1;
                int x = it;
                while(st.find(x + 1) != st.end()) {
                    x++;
                    cnt++;
                }
                mx = max(mx, cnt);
            }
        }
        return mx;
    }
};