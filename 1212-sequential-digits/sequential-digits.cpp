class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string s = "123456789";
        int l = log10(low) + 1;
        int h = log10(high) + 1;
        set<int> ans;
        while(l <= h){
            for(int i = 0 ; i < s.size() ; i++) {
                string sub = s.substr(i, l);
                int a = stoi(sub);
                if(a >= low and a <= high) ans.insert(a);
            }
            l++;
        }   
        // sort(ans.begin(), ans.end());
        vector<int> res;
        for(auto it : ans) res.push_back(it);
        return res;
    }
};