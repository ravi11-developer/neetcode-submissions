class unionFind {
    vector<int> parent;
    vector<int> size;

   public:
    unionFind(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 1; i < n; i++) {
            parent[i] = i;
        }
    }
    int find(int x) {
        if (parent[x] == x) return x;
       return  parent[x] = find(parent[x]);
    }
    int unite(int a, int b) {
        int x = find(a);
        int y = find(b);
        if (x == y) return -1;
        if (size[x] < size[y]) {
            parent[x] = y;
            size[y] += size[x];
        } else {
            parent[y] = x;
            size[x] += size[y];
        }
        return 1;
    }
};
class Solution {
   public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        unionFind dsu(edges.size());
        // vector<int>ans;
        for (auto e : edges) {
            if(dsu.unite(e[0],e[1])==-1) return {e[0],e[1]};
        }
        return { };
    }
};
