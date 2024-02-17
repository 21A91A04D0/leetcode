class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladder) {
        vector<int> d;
        for(int i = 1 ; i < heights.size() ; i++) {
            if(heights[i] > heights[i - 1]) {
                d.push_back(heights[i] - heights[i - 1]);
            }
            else {
                d.push_back(0);
            }    
        }
        // if(bricks == 0 and ladder == 0)return 1;
        for(auto it : d) cout << it << " ";
        priority_queue<int> pq;
        int i = 0;
        while(i < d.size()) {
            cout << i << " ";
            pq.push(d[i]);
            bricks -= d[i];
            
            if(bricks < 0 and ladder > 0) {
                bricks +=  pq.top();
                ladder--;
                pq.pop();
            }
            if(bricks < 0 and ladder == 0) return i;
            i++;
        }
        return i;

        
    }
};