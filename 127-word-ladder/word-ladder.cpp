class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        st.erase(beginWord);
        while(!q.empty()) {
            string s = q.front().first;
            int val = q.front().second;
            q.pop();
            if(s == endWord) return val;
            for(int i = 0 ; i < s.size(); i++) {
                char c = s[i];
                for(int j = 'a' ; j <= 'z' ; j++) {
                    s[i] = j;
                    if(st.find(s) != st.end()) {
                        q.push({s,val + 1});
                        st.erase(s);
                    }
                }
                s[i] = c;
            }
        }
        return 0;
    }
};