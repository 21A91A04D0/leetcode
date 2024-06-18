class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        priority_queue<pair<int, int> >pq;
        for(int i = 0; i < profit.size(); i++) {
            pq.push({profit[i],difficulty[i]});
        }
        sort(worker.begin(), worker.end());
        int j = worker.size() - 1;
        int ans = 0;
        while(!pq.empty() && j >= 0) {
            int p = pq.top().first;
            int d = pq.top().second;
            if(d <= worker[j]) {
                ans += p;
                j--;
            }
            else {
                pq.pop();
            }
            
        }
        return ans;
    }
};