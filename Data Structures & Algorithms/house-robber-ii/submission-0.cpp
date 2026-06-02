class Solution {
   public:
    int helper(vector<int>& nums, int l, int r) {
        int prev2 = 0, prev1 = 0;

        for (int i = l; i <= r; i++) {
            int curr = max(prev1, prev2 + nums[i]);
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 1) return nums[0];

        return max(helper(nums, 0, n - 2), helper(nums, 1, n - 1));
    }
};