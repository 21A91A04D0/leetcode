class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int i = 0; int j = tokens.size() - 1;
        int score = 0;
        int mx = 0;
        while(i <= j) {
            if(power >= tokens[i]) {
                score++;
                mx = max(mx, score);
                power -= tokens[i];
                i++;
            }
            else if(score > 0 and power < tokens[i]){
                score--;
                power += tokens[j];
                j--;
            }
            if(score <= 0 and power < tokens[i]) return mx;
        }
        // if(score <= 0) return 0;
        return mx;
    }
};