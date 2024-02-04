class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> target(52,0);
        vector<int> temp(52, 0);
        int t_cnt = 0;
        // if(s == t) return s;
        for(auto it : t) {
            if(it < 'a'){
                if(target[it - 'A'] == 0) t_cnt++;
                target[it - 'A']++;
            }
            else {
                if(target[it - 'a' + 26] == 0) t_cnt++;
                target[it - 'a' + 26]++;
            }
        }
        int i = 0;
        int j = 0;
        int temp_cnt = 0;
        string res = "";
        int range = s.size();
        while(i < s.size()) {
            if(s[i] < 'a'){
                temp[s[i] - 'A']++;
                if(target[s[i] - 'A'] == temp[s[i] - 'A']){
                    temp_cnt++;
                }
                if(temp_cnt == t_cnt){
                    while(temp_cnt == t_cnt) {
                        if(s[j] < 'a'){
                            temp[s[j]-'A']--;
                            if(temp[s[j] - 'A'] < target[s[j] - 'A']) temp_cnt--;
                        }
                        else{
                            temp[s[j] - 'a' + 26]--;
                            if(temp[s[j] - 'a' + 26] < target[s[j] - 'a' + 26]) temp_cnt--;
                        }
                        j++;
                    }
                    if((i - j) + 2 <= range) {
                        range = (i - j) + 2;
                        res = s.substr(j - 1, range);
                    }
                }
            }
            else {
                temp[s[i] - 'a' + 26]++;
                if(target[s[i] - 'a' + 26] == temp[s[i] - 'a' + 26]){
                    temp_cnt++;
                }
                if(temp_cnt == t_cnt){
                    while(temp_cnt == t_cnt) {
                        if(s[j] < 'a'){
                            temp[s[j]-'A']--;
                            if(temp[s[j] - 'A'] < target[s[j] - 'A']) temp_cnt--;
                        }
                        else{
                            temp[s[j] - 'a' + 26]--;
                            if(temp[s[j] - 'a' + 26] < target[s[j] - 'a' + 26]) temp_cnt--;
                        }
                        
                        j++;
                    }
                    if((i - j) + 2 <= range) {
                        range = (i - j) + 2;
                        res = s.substr(j - 1, range);
                    }
                } 
            }
            i++;
        }
    
        return res;
    }
};