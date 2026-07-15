class Solution {
   public:
    struct Compare {
        bool operator()(const vector<int>& a, const vector<int>& b) const {
            return a > b;  // Uses vector's built-in lexicographical comparison
        }
    };
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>> effort(m, vector<int>(n, INT_MAX));
        priority_queue<vector<int>, vector<vector<int>>, Compare> pq;
        effort[0][0] = 0;
        pq.push({0, 0, 0});
        while (!pq.empty()) {
            auto token = pq.top();
            int diff = token[0];
            int x = token[1];
            int y = token[2];
            if (x == m - 1 && y == n - 1) return diff;
            pq.pop();
            int nx[] = {0, 0, 1, -1};
            int ny[] = {1, -1, 0, 0};
            for (int i = 0; i < 4; i++) {
                int dx = x + nx[i];
                int dy = y + ny[i];
                if (dx >= 0 && dy >= 0 && dx < m && dy < n) {
                    if (effort[dx][dy] == INT_MAX) {
                        effort[dx][dy] = max(diff, abs(heights[dx][dy] - heights[x][y]));
                        pq.push({effort[dx][dy], dx, dy});
                    } else {
                        if (effort[dx][dy] > max(diff, abs(heights[dx][dy] - heights[x][y]))) {
                            effort[dx][dy] = max(diff, abs(heights[dx][dy] - heights[x][y]));
                            pq.push({effort[dx][dy], dx, dy});
                        }
                    }
                }
            }
        }
        return 0;
    }
};