class Solution {
public:
    string intToRoman(int num) {
        string res = "";
        // return res;
        while(num >= 1000) {
            num -= 1000;
            res.push_back('M');
        }
        while(num >= 900) {
            num -= 900;
            res += "CM";
        }
        while(num >= 500) {
            num -= 500;
            res.push_back('D');
        }
        while(num >= 400) {
            num -= 400;
            res += "CD";
        }
        while(num >= 100) {
            num -= 100;
            res.push_back('C');
        }
        while(num >= 90) {
            num -= 90;
            res += "XC";
        }
        while(num >= 50) {
            num -= 50;
            res.push_back('L');
        }
        while(num >= 40) {
            num -= 40;
            res += "XL";
        }
        while(num >= 10) {
            num -= 10;
            res.push_back('X');
        }
        while(num >= 9) {
            num -= 9;
            res += "IX";
        }
        while(num >= 5) {
            num -= 5;
            res.push_back('V');
        }
        while(num >= 4) {
            num -= 4;
            res += "IV";
        }
        while(num >= 1) {
            num -= 1;
            res.push_back('I');
        }
        return res;
    }
};