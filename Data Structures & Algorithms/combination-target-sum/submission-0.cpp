class Solution {
   public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> curr;

        utility(ans, nums, 0, target, curr, 0);

        return ans;
    }
    void utility(vector<vector<int>>& ans, const vector<int>& nums, int currSum, int target,
                 vector<int>& currele, int idx) {
        if (currSum > target) return;

        if (currSum == target) {
            ans.push_back(currele);
            return;
        }

        for (int i = idx; i < nums.size(); i++) {
            currele.push_back(nums[i]);

            utility(ans, nums, currSum + nums[i], target, currele, i);

            currele.pop_back();
        }
    }
};
