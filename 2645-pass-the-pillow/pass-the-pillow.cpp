class Solution {
public:
    int passThePillow(int n, int time) {
        int o = time / (n - 1) + 1;
        if(o % 2) {
            return time % (n - 1) + 1;
        }
        else {
            return n - (time % (n - 1));
        }
    }
};