class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        string ans;
        for(auto it : words) {
            string res = it;
            reverse(res.begin(), res.end());
            if(res == it) {
                ans = it;
                break;
            }
        }
        return ans;
    }
};