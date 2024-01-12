class Solution {
public:
    bool halvesAreAlike(string s) {
        int first = 0;
        int second = 0;
        int len = s.size() / 2;
        string vow = "AEIOUaeiou";
        for (int i = 0 ; i < len ; i++) {
            // one.push_back(s[i]);
            if(vow.find(s[i]) < vow.size()) first++;
        }
        for(int j = len ; j < s.size() ; j++) {
            if(vow.find(s[j]) < vow.size()) second++;
        }
        // cout << first << " " << second;
        if(first == second) return true;
        return false;
    }
};