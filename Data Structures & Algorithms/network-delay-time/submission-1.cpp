class Solution {
   public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<vector<int>>> edges(n + 1);
        for (auto i : times) {
            edges[i[0]].push_back({i[1], i[2]});
        }
        vector<int> distance(n + 1, INT_MAX);
        distance[0] = 0;
        distance[k] = 0;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, k});
        while (!pq.empty()) {
            auto t = pq.top();
            pq.pop();
            int d = t[0];
            int node = t[1];
            for (auto nbr : edges[node]) {
                if (distance[nbr[0]] == INT_MAX) {
                    distance[nbr[0]] = d + nbr[1];
                    pq.push({distance[nbr[0]], nbr[0]});
                } else {
                    if (distance[nbr[0]] > d + nbr[1]) {
                        distance[nbr[0]] = d + nbr[1];
                        pq.push({distance[nbr[0]], nbr[0]});
                        // pq.push({nbr[0], distance[nbr[0]]});
                    }
                }
            }
        }
        int ans = INT_MIN;
        // for(int i:distance){
        //     cout<<i<<" ";
        // }
        for (int i = 1; i <= n; i++) {
            ans = max(ans, distance[i]);
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
