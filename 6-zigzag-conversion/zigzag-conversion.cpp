class Solution {
public:
    string convert(string s, int numRows) {
        // return "";
        vector<int> zig;
        int k = 0;
        int i = 0;
        if(numRows < 2) return s;
        while(i < s.size()) {
            while(k < numRows && i < s.size()) {
                zig.push_back(k);
                k++;
                i++;
            }
            k-=2;
            while(k >= 0 && i < s.size()) {
                zig.push_back(k);
                k--;
                i++;
            }
            k+=2;
        }
        string res = "";
        for(int i = 0; i < numRows; i++) {
            for(int j = 0; j < s.size(); j++) {
                if(i == zig[j]) res.push_back(s[j]);
            }
        }
        return res;
    }
};