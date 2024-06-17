class Solution {
public:
    int lengthOfLastWord(string s) {
        int length = 0;
        for(int i = s.size() - 1; i >= 0 ; i--) {
            if( s[i] != ' ') length++;
            else if(s[i] == ' ' and length == 0) continue;
            else if(s[i] == ' ' and length != 0) return length;
        }
        return length;
    }
};