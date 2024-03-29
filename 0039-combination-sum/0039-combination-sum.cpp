class Solution {
public:
    vector<vector<int>> ans;
    void fun(int ind, vector<int> &candidates, int target, vector<int> curr) {
    if(ind == candidates.size()) {
        if(target == 0) {
            ans.push_back(curr);
        }
        return;
    }
        
        if(ind >= candidates.size() || target < 0) return;
        fun(ind + 1, candidates, target, curr);
        if(candidates[ind] <= target){
            curr.push_back(candidates[ind]);
            fun(ind, candidates, target - candidates[ind], curr);
            curr.pop_back();  
        } 
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        fun(0, candidates, target, {});
        return ans;
    }
};