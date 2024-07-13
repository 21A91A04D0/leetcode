class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        vector<pair<int, int>> p;
        for(int i = 0 ; i < positions.size() ; i++) {
            p.push_back({positions[i], i});
        }
        sort(p.begin(), p.end());
        for(int i = 0 ; i < p.size() ; i++) {
            positions[i] = p[i].first;
        }
        
        int n = p.size();
        for(int i = 0 ; i < n ; i++) {
            directions.push_back(directions[p[i].second]);
            healths.push_back(healths[p[i].second]);
        }
        directions.erase(directions.begin(),directions.begin() + n);
        healths.erase(healths.begin(),healths.begin() + n);
        stack<pair<char, int>> st;
        
        int i = 0;
        for(int i = 0 ; i < n ; i++) {
                while(i<n && !st.empty() && st.top().first == 'R' and directions[i] == 'L') {
                    int ind = st.top().second;
                    if(healths[i] > healths[ind]) {
                        healths[i]--;
                        healths[ind] = 0;
                        st.pop();  
                    }
                    else if(healths[i] < healths[ind]) {
                        healths[ind]--;
                        healths[i] = 0;
                        i++;
                    }
                    else {
                        healths[i] = 0;
                        healths[ind] = 0;
                        st.pop();
                        i++;
                    }
                }
                if(i<n)
                st.push({directions[i],i});
        }
        

        // for(auto it : healths) cout << it << " ";
        // return {};
        vector<pair<int, int> > ans;
        for(int i = 0 ; i < p.size() ; i++) {
            p[i].first = healths[i];
        }
        for(int i = 0 ; i < n ; i++) {
            swap(p[i].first,p[i].second);
        }
        sort(p.begin(), p.end());
        vector<int> anss;
        for(int i = 0 ; i < p.size() ; i++) {
            if(p[i].second != 0) anss.push_back(p[i].second);
        }
        return anss;
    }
};