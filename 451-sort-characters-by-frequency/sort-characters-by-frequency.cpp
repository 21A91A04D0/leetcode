class Solution {
public:
    string frequencySort(string s) {
        priority_queue<pair<int, char>> pq;
        map<char, int> mp;
        for(auto it : s){
            mp[it]++;
        }
        for(auto key : mp) {
            pq.push({key.second, key.first});
        }
        // cout << pq.top().first;
        string s1 = "";
        while(!pq.empty()) {
            char c = pq.top().second;
            int e = pq.top().first;
            while(e) {
                s1.push_back(c);
                e--;
            }
            pq.pop();
        }
        return s1;
    }
};