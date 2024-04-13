class Solution {
public:
    vector<vector<int>> ans;
    vector<int> fun(int n) {
        if(n == 1) {
            ans.push_back({1});
            return {1};
        }
        vector<int> res = fun(n - 1);
        vector<int> pascal = {1};
        for(int i = 1 ; i < res.size() ; i++) {
            pascal.push_back(res[i] + res[i - 1]);
        }
        pascal.push_back(1);
        ans.push_back(pascal);
        return pascal;
    }
    vector<vector<int>> generate(int n) {
        vector<int> a = fun(n);
        return ans;
    }
};