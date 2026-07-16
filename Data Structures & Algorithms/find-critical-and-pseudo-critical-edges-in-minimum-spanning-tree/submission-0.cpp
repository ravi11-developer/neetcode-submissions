class dsu {
    vector<int> parent;
    vector<int> size;

   public:
    dsu(int n) {
        parent.resize(n);
        size.assign(n, 1);

        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int a, int b) {
        int para = find(a);
        int parb = find(b);

        if (para == parb) return;

        if (size[para] < size[parb]) {
            parent[para] = parb;
            size[parb] += size[para];
        } else {
            parent[parb] = para;
            size[para] += size[parb];
        }
    }
};

class Solution {
   public:
    int mst(int n, vector<vector<int>>& edges, int skip, int force) {
        dsu connection(n);

        int weight = 0;
        int cnt = 0;

        if (force != -1) {
            connection.unite(edges[force][0], edges[force][1]);
            weight += edges[force][2];
            cnt++;
        }

        for (int i = 0; i < edges.size(); i++) {
            if (i == skip) continue;

            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];

            if (connection.find(u) != connection.find(v)) {
                connection.unite(u, v);
                weight += w;
                cnt++;
            }
        }

        if (cnt != n - 1) return INT_MAX;

        return weight;
    }

    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        for (int i = 0; i < edges.size(); i++) edges[i].push_back(i);

        sort(edges.begin(), edges.end(),
             [](vector<int>& a, vector<int>& b) { return a[2] < b[2]; });

        int original = mst(n, edges, -1, -1);

        vector<vector<int>> ans(2);

        for (int i = 0; i < edges.size(); i++) {
            if (mst(n, edges, i, -1) > original) {
                ans[0].push_back(edges[i][3]);

            } else if (mst(n, edges, -1, i) == original) {
                ans[1].push_back(edges[i][3]);
            }
        }

        return ans;
    }
};