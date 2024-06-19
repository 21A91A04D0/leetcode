class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int n = bloomDay.size();
        bool f = true;
        while(low <= high) {
            int mid = (low + high) / 2;
            int day = mid;
            int i = 0;
            int j = 0;
            int cnt = 0;
            int temp = 0;
            while(i < n) {
                if(bloomDay[i] <= day) {
                    cnt++;
                    if(i - j + 1 == k) {
                        temp++;
                        j = i + 1;
                    }
                }
                else if(bloomDay[i] > day) {
                    j = i + 1;
                    cnt = 0;
                }
                i++;
            }
            if(temp >= m) {
                f = false;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        if(f == true) return -1;
        return high + 1;
    }
};