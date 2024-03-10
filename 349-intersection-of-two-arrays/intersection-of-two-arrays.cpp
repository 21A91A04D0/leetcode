class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> mp;
        for(int i = 0 ; i < nums1.size() ; i++) {
            mp[nums1[i]]++;
        }
        vector<int> v;
        for(int i = 0 ; i < nums2.size() ; i++) {
            if(mp[nums2[i]] != 0 and find(v.begin(), v.end(),nums2[i]) == v.end()) {
                v.push_back(nums2[i]);
            }
        }
        return v;
    }
};