class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int ans = 0;
        int n = gas.size();
        int level = 0, temp = 0;
        for(int i = 0 ; i < n ; i++) {
            level += (gas[i] - cost[i]);
            temp += (gas[i] - cost[i]);
            if(temp < 0) temp = 0, ans = i + 1;
            // if(level >= 0) return i;
        }
        if(level < 0) return -1;
        return ans;
    }
};