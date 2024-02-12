class Solution {
public:
string final(string s) {
    for(int i = 0 ; i < s.size() ; i++) {
        if(s[i] == 'D') s[i] = 'U';
        else if(s[i] == 'L') s[i] = 'R';
        else s[i] = 'L';
    }
    return s;
}
string fun(char l, char r) {
    string res = "";
    int left = l - 'a';
    int right = r - 'a';
    
    int row_left = left / 5;
    int col_left = left % 5;
    int row_right = right / 5;
    int col_right = right % 5;
    

    int row = abs(row_left - row_right);
    int col = abs(col_left - col_right);
    // cout << row << " " << col;
    if(r == 'z') {
        while(col--) {
            res.push_back('L');
        }
        while(row--) {
            res.push_back('D');
        }
    }
    else {
        while(row--) {
            res.push_back('D');
        }
        if(col_left < col_right) {
            while(col--){
                res.push_back('R');
            }
        }
        else {
            while(col--) {
                res.push_back('L');
            }
        }
    }
    
    return res;
}
    string alphabetBoardPath(string s) {
        string s1 = "";
        s1.push_back('a');
        for(auto it : s) {
            s1.push_back(it);
        }
        string result = "";
        for(int i = 0 ; i < s1.size() - 1; i++) {
            char l = s1[i];
            char r = s1[i + 1];
            if(l == r) {
                result.push_back('!');
                continue;
            }
            string res;
            if(l == 'z') {
                int left = l - 'a';
                int right = r - 'a';
                int row_left = left / 5;
                int col_right = right % 5;
                int row_right = right / 5;
                int col_left = left % 5;
                int row = abs(row_left - row_right);
                int col = abs(col_left - col_right);
                while(row--) {
                    res.push_back('U');
                }
                while(col--) {
                    res.push_back('R');
                }
            }
            else if(l > r) {
                string ans = fun(r, l);
                res = final(ans);
            }
            else {
                res = fun(l, r);
            }
            for(auto it : res) {
                result.push_back(it);
            }
            result.push_back('!');
        }
        return result;
        }
};