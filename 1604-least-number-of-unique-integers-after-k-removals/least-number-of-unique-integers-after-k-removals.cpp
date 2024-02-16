class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        ios_base::sync_with_stdio(false);cin.tie(NULL);
        map<int, int> mp;
        for(auto it : arr) {
            mp[it]++;
        }
        int n = mp.size();
        vector<int> v;
        for(auto it : mp) {
            v.push_back(it.second);
        }
        sort(v.begin(), v.end());
        for(auto it : v) {
            if(it <= k) {
                k-= it;;
                n--;
            }
        }
        return n;
    }
};