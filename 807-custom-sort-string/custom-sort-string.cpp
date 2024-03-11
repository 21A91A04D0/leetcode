class Solution {
public:
    string customSortString(string order, string s) {
        string in = "";
        string no = "";
        map<char, int> o_mp;
        map<char, int> s_mp;
        for(auto it : order) {
            o_mp[it]++;
        }
        for(auto it : s) {
            s_mp[it]++;
        }
        for(int i = 0 ; i < s.size() ; i++) {
            if(o_mp[s[i]] != 0) {
                in.push_back(s[i]);
            }
            else {
                no.push_back(s[i]);
            }
        }
        map<char, int> a_mp;
        for(auto it : in) {
            a_mp[it]++;
        }
        string ans = "";
        for(int i = 0 ; i < order.size() ; i++) {
            if(a_mp[order[i]] != 0) {
                int f = a_mp[order[i]];
                while(f--) {
                    ans.push_back(order[i]);
                }
                
            }
        }
        return ans + no;
    }
};