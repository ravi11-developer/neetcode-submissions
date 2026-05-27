class Solution {
   public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> prefixMax(n, INT_MIN);
        vector<int> suffixMax(n, INT_MIN);
        prefixMax[0] = height[0];
        for (int i = 1; i < n; i++) {
            prefixMax[i] = max(height[i], prefixMax[i - 1]);
        }
        suffixMax[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            // int x=suffixMax[i];
            suffixMax[i] = max(height[i], suffixMax[i + 1]);
        }
        int score = 0;
        for (int i = 1; i < n - 1; i++) {
            score += min(prefixMax[i], suffixMax[i]) - height[i];
        }
        return score;
    }
};
