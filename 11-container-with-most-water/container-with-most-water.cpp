class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0;
        int mx = 0;
        int j = height.size() - 1;
        while(i < j) {
            int l = j - i;
            int h = min(height[i],height[j]);
            mx = max(mx, l * h);
            if(height[i] <= height[j]) {
                i++;
            }
            else j--;
        }
        return mx;
    }
};