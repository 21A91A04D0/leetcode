class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string temp = strs[0];
        string res = "";
        for(int i = 0; i < temp.size(); i++) {
            for(int j = 0; j < strs.size(); j++) {
                if(temp[i] != strs[j][i]) return res;
                
            }
            res.push_back(temp[i]);
        }
        return temp;
    }
};