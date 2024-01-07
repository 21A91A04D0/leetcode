class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int n) {
        int res = 0;
        vector<int> A;
        for(int i = 0 ; i < nums.size() ; i++){
            res ^= nums[i];
        }
        int ans = res;
        for(int i = nums.size() - 1 ; i >= 0 ; i--) {
            int j = 0;
            int finall = 0;
            while(j < n){
                int mask = (1 << j);
                if((res ^ mask) > res){
                    finall += mask;
                    res = (res ^ finall);
                }
                j++;

            }
            A.push_back(finall);
            res = (ans ^ nums[i]);
            ans = res;
        }
        return A;
    }
};