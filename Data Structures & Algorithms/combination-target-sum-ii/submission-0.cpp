class Solution {
    int t;
    vector<vector<int>> ans;

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());   
        t = target;

        vector<int> temp;
        func(candidates, temp, 0, 0);

        return ans;
    }

    void func(vector<int>& cand, vector<int>& temp, int tempSum, int idx) {
        if (tempSum > t) return;

        if (idx == cand.size()) {
            if (tempSum == t)
                ans.push_back(temp);
            return;
        }

        int next = idx;
        while (next + 1 < cand.size() && cand[next] == cand[next + 1])
            next++;

        func(cand, temp, tempSum, next + 1);

        
        temp.push_back(cand[idx]);
        func(cand, temp, tempSum + cand[idx], idx + 1);
        temp.pop_back();
    }
};