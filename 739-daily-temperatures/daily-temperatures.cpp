class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        stack<pair<int, int>> st;
        vector<int> v(temp.size(),0);
        for(int i = temp.size() - 1 ; i >= 0 ; i--) {
            int val = temp[i];
            while(!st.empty()) {
                if(st.top().first > temp[i]) {
                    v[i] = (st.top().second - i);
                    // st.pop();
                    st.push({temp[i], i});
                    break;
                }
                st.pop();
            }
            st.push({temp[i], i});
        }
        return v;
    }
};