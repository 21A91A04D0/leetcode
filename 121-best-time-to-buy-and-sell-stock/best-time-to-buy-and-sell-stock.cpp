class Solution {
public:
    int maxProfit(vector<int>& prices) {
        stack<int> st;
        int mx = 0;
        for(int i = prices.size() - 1 ; i >= 0 ; i--) {
            if(st.empty() || prices[i] > st.top()) st.push(prices[i]);
            else {
                mx = max(st.top() - prices[i], mx);
            }
        }
        return mx;
    }
};