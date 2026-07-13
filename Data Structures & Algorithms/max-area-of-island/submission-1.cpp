#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define dbg(x) cerr << #x << " = " << x << endl;
class Solution
{

public:
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        int ans = 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1 && visited[i][j] == false)
                {
                    ans = max(ans, dfs(grid, visited, i, j));
                }
            }
        }
        return ans;
    }
    int dfs(vector<vector<int>> &grid, vector<vector<bool>> &visited, int i, int j)
    {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        q.push({i,j});
        visited[i][j] = true;
        int area = 1;
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
                if (dx >= 0 && dy >= 0 && dx < m && dy < n && grid[dx][dy] == 1 && visited[dx][dy] == false)
                {
                    visited[dx][dy] = true;
                    // cout << "IN\n";
                    area++;
                    q.push({dx, dy});
                }
            }
        }
        return area;
    }
};
