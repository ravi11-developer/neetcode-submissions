class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        vector<vector<pair<int,int>>> adj(n);

        for(auto &f:flights){
            adj[f[0]].push_back({f[1],f[2]});
        }

        vector<int> dist(n,INT_MAX);

        queue<pair<int,pair<int,int>>> q;

        q.push({0,{src,0}});

        dist[src]=0;

        while(!q.empty()){

            auto cur=q.front();
            q.pop();

            int stops=cur.first;
            int node=cur.second.first;
            int cost=cur.second.second;

            if(stops>k)
                continue;

            for(auto &it:adj[node]){

                int next=it.first;
                int wt=it.second;

                if(cost+wt<dist[next]){

                    dist[next]=cost+wt;

                    q.push({stops+1,{next,cost+wt}});
                }
            }
        }

        if(dist[dst]==INT_MAX)
            return -1;

        return dist[dst];
    }
};