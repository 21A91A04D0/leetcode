class Solution {
public:
    string reverseWords(string s) {
        vector<string> v;
        string st = "";
        for(int i = 0; i < s.size(); i++) {
            if(st != "" && s[i] == ' ') {
                v.push_back(st);
                st = "";
            }
            else if(s[i] != ' ') st.push_back(s[i]);
        }
        if(st != "") v.push_back(st);
        reverse(v.begin(), v.end());
        st = "";
        for(int i = 0; i < v.size(); i++) {
            st += v[i];
            if(i != v.size() - 1) {
                st.push_back(' ');
            }
        }
        return st;
    }
};