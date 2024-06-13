class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> mp;
        int left = 0, right = 0;
        int maxLen = 0;
        int n = s.size();
        while(right < n) {
            if(mp.find(s[right]) == mp.end()) {
                maxLen = max(maxLen, right - left + 1);
            }
            else {
                left = max(mp[s[right]] + 1, left);
                if(mp[s[right]] < left) {
                    maxLen = max(maxLen, right - left + 1);
                }
            }
            mp[s[right]] = right;
            right++;
        }   
        
        return maxLen;
    }
};