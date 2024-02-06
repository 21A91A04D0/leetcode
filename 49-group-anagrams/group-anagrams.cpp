class Solution {
public:
    string fun(string s){
        sort(s.begin(), s.end());
        return s;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> dp;
        vector<string> ans;
        map<string,vector<string>> mp;
        for(int i = 0 ; i < strs.size() ; i++) {
            ans.push_back(fun(strs[i]));
        }
        for(auto it : strs) {
            string ans = fun(it);
            if(mp.find(ans) == mp.end()) {
                mp[ans] = {it};
            }
            else {
                mp[ans].push_back(it);
            }
        }
        for(auto it : mp) {
            vector<string> B;
            for(auto val : it.second) {
                B.push_back(val);
            }
            dp.push_back(B);
        }
        return dp;
    }
};