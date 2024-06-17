class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        int l = 0;
        int r = 0;
        int c = 0, n = s.size();
        while(c < n) {
            while(c < n && s[c] == ' ') c++;
            if(c == n) break;
            while(c < n && s[c] != ' ') {
                s[r] = s[c];
                r++;
                c++;
            }
            
            reverse(s.begin() + l, s.begin() + r);
            s[r++] = ' ';
            l = r;
            c++;
        }
        s.resize(r - 1);
        return s;
    }
};