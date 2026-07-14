class Solution {
public:
    void bfs(queue<pair<int,int>>& q,
             vector<vector<bool>>& vis,
             vector<vector<int>>& heights)
    {
        int m = heights.size();
        int n = heights[0].size();

        int dr[] = {-1,1,0,0};
        int dc[] = {0,0,-1,1};

        while(!q.empty()){
            auto [r,c] = q.front();
            q.pop();

            for(int k=0;k<4;k++){
                int nr = r + dr[k];
                int nc = c + dc[k];

                if(nr<0 || nr>=m || nc<0 || nc>=n)
                    continue;

                if(vis[nr][nc])
                    continue;

                if(heights[nr][nc] >= heights[r][c]){
                    vis[nr][nc] = true;
                    q.push({nr,nc});
                }
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        int m = heights.size();
        int n = heights[0].size();

        vector<vector<bool>> pac(m, vector<bool>(n,false));
        vector<vector<bool>> atl(m, vector<bool>(n,false));

        queue<pair<int,int>> pq, aq;

        // pacific
        for(int i=0;i<m;i++){
            pq.push({i,0});
            pac[i][0]=true;
        }

        for(int j=1;j<n;j++){
            pq.push({0,j});
            pac[0][j]=true;
        }

        // atlantic
        for(int i=0;i<m;i++){
            aq.push({i,n-1});
            atl[i][n-1]=true;
        }

        for(int j=0;j<n-1;j++){
            aq.push({m-1,j});
            atl[m-1][j]=true;
        }

        bfs(pq,pac,heights);
        bfs(aq,atl,heights);

        vector<vector<int>> ans;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(pac[i][j] && atl[i][j])
                    ans.push_back({i,j});
            }
        }

        return ans;
    }
};