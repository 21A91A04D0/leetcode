class Solution {
public:
    int minimumLength(string s) {
        int i = 0;
        int j = s.size() - 1;
        while(i < j) {
            if(s[i] != s[j]) return j - i + 1;
            else if(s[i] == s[j]) {
                char ch = s[i];
                while(s[i] == ch and i <= j) {
                    i++;
                }
                while(s[j] == ch and i < j) {
                    j--;
                }
            }
        }
        if(i == j) return 1;
        return 0;
    }
};