class Solution {
   public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) q.push({i, j});
            }
        }
        int minTime = 0;
        while (!q.empty()) {
            queue<pair<int, int>> qt;
            while (!q.empty()) {
                auto [x, y] = q.front();
                q.pop();
                int nx[] = {0, 1, 0, -1};
                int ny[] = {1, 0, -1, 0};
                for (int i = 0; i < 4; i++) {
                    int dr = x + nx[i];
                    int dy = y + ny[i];
                    if (dr >= 0 && dy >= 0 && dr < m && dy < n && grid[dr][dy] == 1) {
                        qt.push({dr, dy});
                        grid[dr][dy] = 2;
                    }
                }
            }
            if(qt.empty()) break;
            minTime++;
            q=qt;
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) return -1; 
            }
        }
        return minTime;
    }
};