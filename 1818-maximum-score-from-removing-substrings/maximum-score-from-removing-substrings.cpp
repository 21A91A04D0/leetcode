class Solution {
public:

    int maximumGain(string s, int x, int y) {
        stack<char> st;
        stack<char> sp;
        int ans = 0;
        if(y > x) {
            for(int i = 0 ; i < s.size(); i++) {
                if(s[i] == 'a' and !st.empty() and st.top() == 'b') {
                    st.pop();
                    ans += y;
                }
                else {
                    st.push(s[i]);
                }
            }
            string stt = "";
            while(!st.empty()) {
                stt.push_back(st.top());
                st.pop();
            }
            reverse(stt.begin(), stt.end());
            
            for(int i = 0 ; i < stt.size() ; i++) {
                if(stt[i] == 'b' and !sp.empty() and sp.top() == 'a') {
                    sp.pop();
                    ans += x;
                }
                else {
                    sp.push(stt[i]);
                }
            }
        }
        else {
            for(int i = 0 ; i < s.size(); i++) {
                if(s[i] == 'b' and !st.empty() and st.top() == 'a') {
                    st.pop();
                    ans += x;
                }
                else {
                    st.push(s[i]);
                }
            }
            string stt = "";
            while(!st.empty()) {
                stt.push_back(st.top());
                st.pop();
            }
            reverse(stt.begin(), stt.end());
            
            for(int i = 0 ; i < stt.size() ; i++) {
                if(stt[i] == 'a' and !sp.empty() and sp.top() == 'b') {
                    sp.pop();
                    ans += y;
                }
                else {
                    sp.push(stt[i]);
                }
            }
            
            
        }
        return ans;
    }
};