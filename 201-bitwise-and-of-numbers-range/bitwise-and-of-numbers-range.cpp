class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        // if(left == right) return left;
        int low = 0;
        int ind = 0;
        for(int i = 31 ; i >= 0 ; i--) {
            if((left & (1 << i)) > 0) {
                low = (1 << i);
                ind = i;
                break;
            }
        }
        int high = 0;
        if(ind == 30) {
            high = 2147483647;
        }
        else if(ind < 30) {
            high = low << 1;
        }
        int res = left;
        cout << low << " " << high;
        if(left >= low and right <= high) {
            int i = left;
            while(i <= right) {
                if(i < 2147483647) {
                    res = res & i;
                    i++;
                }
                else {
                    break;
                }
            }
            return res;
        }
        return 0;
        
    }
};