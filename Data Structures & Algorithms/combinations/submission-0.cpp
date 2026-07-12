class Solution {
    vector<vector<int>> ans;

   public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> temp;
        f(1, temp, k, n);
        return ans;
    }
    void f(int idx, vector<int>& temp, int k, int n) {

        if (temp.size() == k) {
            ans.push_back(temp);
            return;
        }
        if (idx > n) return;
        f(idx + 1, temp, k, n);
        temp.push_back(idx);
        f(idx + 1, temp, k, n);
        temp.pop_back();
    }
};