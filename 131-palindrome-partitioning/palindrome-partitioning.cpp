class Solution {
public:
    void hero(int ind, string &s, vector<vector<string>> &v, vector<string> &ds) {
        if(ind >= s.size()){
            v.push_back(ds);
            return;
        }
        for(int i = ind ; i < s.size() ; i++) {
            string sub = s.substr(ind, i - ind + 1);
            string rev = sub;
            reverse(rev.begin(), rev.end());
            if(rev == sub) {
                ds.push_back(rev);
                hero(i + 1, s, v, ds);
                ds.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> v;
        vector<string> ds;
        hero(0, s, v, ds);
        return v;
    }
};