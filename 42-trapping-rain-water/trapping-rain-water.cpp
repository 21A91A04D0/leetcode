class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> prefix;
        vector<int> suffix(height.size(), 0);
        for(int i = 0; i < height.size(); i++) {
            if(i == 0) prefix.push_back(height[i]);
            else prefix.push_back(max(height[i], prefix[i - 1]));
        }
        for(int i = height.size() - 1; i >= 0; i--) {
            if(i == height.size() - 1) suffix[i] = height[i];
            else suffix[i] = max(suffix[i + 1], height[i]);
        }
        int ans = 0;
        for(int i = 0; i < height.size(); i++) {
            ans += (min(prefix[i], suffix[i]) - height[i]);
        }
        return ans;
    }
};