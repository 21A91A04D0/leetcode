class Solution {
public:
    bool palind(string s) {
        string t = s;
        reverse(t.begin(), t.end());
        return t == s;
    }
    bool validPalindrome(string s) {
        bool flag = true;
        int i = 0;
        int j = s.size() - 1;
        while(i < j) {
            if(s[i] != s[j] && flag) {
                flag = false;
                if(i + 1 == j) return true;
                break;
            }
            else if(s[i] == s[j]) {
                i++;
                j--;
            }
        }
        string temp1 = "";
        string temp2 = "";
        for(int ind = i ; ind < j ; ind++) {
            temp1 += s[ind];
        }
        for(int ind = i + 1; ind <= j ; ind++) {
            temp2 += s[ind];
        }
        if(palind(temp1) || palind(temp2)) return true;
        return false;
    }
};