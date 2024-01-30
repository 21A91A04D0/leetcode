class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(auto it : tokens) {
            if(it == "+") {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                int ans = a + b;
                st.push(ans);
            }
            else if(it == "*") {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                int ans = a * b;
                st.push(ans);
            }
            else if(it == "/") {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                int ans = b / a;
                st.push(ans);
            }
            else if(it == "-") {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                int ans = b - a;
                st.push(ans);
            }
            else {
                
                st.push(stoi(it));
            }
        }
        return st.top();
    }
};