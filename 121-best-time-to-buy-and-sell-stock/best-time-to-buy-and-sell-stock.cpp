class Solution {
public:
    int maxProfit(vector<int>& prices) {
        stack<int> st;
        int mx = 0;
        for(int i = prices.size() - 1; i >= 0; i--) {
            if(st.empty()) st.push(prices[i]);
            else if(st.top() > prices[i]) {
                mx = max(mx, st.top() - prices[i]);
            }
            else if(st.top() < prices[i]) {
                st.push(prices[i]);
            }
        }
        return mx;
    }
};