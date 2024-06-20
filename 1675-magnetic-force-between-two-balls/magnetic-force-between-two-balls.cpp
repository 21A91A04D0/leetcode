class Solution {
public:
    int fun(vector<int> & position, long long mid) {
        int temp = 1;
        int prev = position[0], i = 1;
        while(i < position.size()) {
            if(position[i] - prev >= mid) {
                temp++;
                prev = position[i];
            }
            i++;
        }
        return temp;
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        // int low = *min_element(position.begin(), position.end());
        int low = 1;
        int high = *max_element(position.begin(), position.end());
        while(low <= high) {
            long long mid = (low + high) >> 1;
            if(fun(position,mid) >= m) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return low - 1;
    }
};