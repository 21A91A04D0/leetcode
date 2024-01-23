class Solution {
public:
    vector<string> s;
    void subsets(string curr, int ind, vector<string> &arr) {
        
        if(ind == arr.size()) {
            if(curr.size() > 26) return;
            s.push_back(curr);
            return;
        }
        subsets(curr, ind + 1, arr);
        subsets(curr + arr[ind],ind+1, arr);
    }
    int maxLength(vector<string>& arr) {
        int mx = 0;
        subsets("", 0, arr);
        
        for(int i = 0 ; i < s.size() ; i++){
            unordered_map<char, int> st;
            for(int j = 0 ;j < s[i].size() ; j++) {
                st[s[i][j]]++;
            }
            
            if(st.size() > mx && st.size() == s[i].size()) mx = st.size();
                
        }
        return mx;
    }
};