class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char, int>ms;
        map<char, int>mt;
        for(auto it : s) {
            ms[it]++;
        }
        for(auto it : t) {
            mt[it]++;
        }
        map<char, char> mp;
        for(int i = 0 ; i < s.size() ; i++) {
            if(ms[s[i]] != mt[t[i]]) return 0;
            else {
                if(mp.find(s[i]) == mp.end()) {
                    mp[s[i]] = t[i];
                }
                else {
                    char prev = mp[s[i]];
                    if(prev != t[i]) return 0;
                }
            }
        }
        return 1;
    }
};