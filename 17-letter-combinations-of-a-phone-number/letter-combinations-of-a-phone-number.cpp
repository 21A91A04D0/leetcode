class Solution {
public:
vector<string> val = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    void phone(int i, string &dig, vector<string> &ans, string ds) {
        if(dig[i] == '1' || dig[i] == '0') return;
        if(i >= dig.size()) {
            if(ds != "") ans.push_back(ds);
            
            return;
        }
        int ind = dig[i] - '0';
        for(int k = 0 ; k < val[ind].size() ; k++) {
            phone(i + 1, dig, ans, ds + val[ind][k]);
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        string ds = "";
        phone(0, digits, ans, ds);
        return ans;
    }
};