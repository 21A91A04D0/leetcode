class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int mx = nums[n - 1] + 1;
        int mn = nums[0];
        vector<int> missing;
        set<int> st;
        for (auto it : nums)
            st.insert(it);
        vector<int> v = nums;
        nums.clear();
        for (auto it : st) {
            nums.push_back(it);
        }
        int i = 0;
        while (i < nums.size()) {
            if (nums[i] != mn && nums[i] > mn) {
                missing.push_back(mn);
                
            }
            else i++;
            mn++;
        }
        for(auto it: nums) cout << it << " ";
        cout << endl;
        for(auto it : missing) cout << it << " ";
        cout << endl;
        int j = 0;
        int ans = 0;
        int m = 1;
        while(m < n) {
            while(j < missing.size() && missing[j] < v[m]) {
                    j++;
                }
            if (v[m] == v[m - 1] && j < missing.size()) {
                
                ans += (missing[j] - v[m]);
                j++;
            } else if (v[m] == v[m - 1] && j >= missing.size()) {
                
                ans += (mx - v[m]);
                mx++;
            }
            m++;
            
        }
        return ans;
    }
};