class Solution {
   public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O') {
                visited[i][0] = true;
                q.push({i, 0});
            }
            if (board[i][n - 1] == 'O') {
                visited[i][n - 1] = true;
                q.push({i, n - 1});
            }
        }
        for (int i = 0; i < n; i++) {
            if (board[0][i] == 'O') {
                visited[0][i] = true;
                q.push({0, i});
            }
            if (board[m - 1][i] == 'O') {
                visited[m - 1][i] = true;
                q.push({m - 1, i});
            }
        }
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            int nx[] = {1, -1, 0, 0};
            int ny[] = {0, 0, -1, 1};
            for (int i = 0; i < 4; i++) {
                int dx = x + nx[i];
                int dy = y + ny[i];
                if (dx >= 0 && dy >= 0 && dx < m && dy < n && visited[dx][dy] == false &&
                    board[dx][dy] == 'O') {
                    visited[dx][dy] = true;
                    q.push({dx, dy});
                }
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (visited[i][j] == false && board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }
};
