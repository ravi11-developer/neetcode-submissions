class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int,int>>q;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 0 )
                {
                    visited[i][j]=true;
                    q.push({i,j});
                }
            }
        }
        dfs(grid,visited,q);
        return ;
    }
    void dfs(vector<vector<int>> &grid, vector<vector<bool>> &visited,queue<pair<int,int>>&q)
    {
        int m = grid.size();
        int n = grid[0].size();
        while (!q.empty())
        {
            auto [x, y] = q.front();
            q.pop();
            int nx[] = {1, 0, -1, 0};
            int ny[] = {0, 1, 0, -1};
            for (int i = 0; i < 4; i++)
            {
                int dx = x + nx[i];
                int dy = y + ny[i];
                if (dx >= 0 && dy >= 0 && dx < m && dy < n && grid[dx][dy]==2147483647 && visited[dx][dy] == false)
                {
                    visited[dx][dy] = true;
                    grid[dx][dy]=grid[x][y]+1;
                    q.push({dx, dy});
                }
            }
        }
        return ;
    }

};
