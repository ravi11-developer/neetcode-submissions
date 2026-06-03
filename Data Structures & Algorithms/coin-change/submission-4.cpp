class Solution {
    map<int, int> mp;

   public:
    int coinChange(vector<int>& coins, int amount) {
        mp.clear();
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            int x = INT_MAX;
            for (int j : coins) {
                int y = (i - j) < 0 ? INT_MAX : dp[i - j];
                x = min(x, y);
            }
            if (x == INT_MAX)
                dp[i] = INT_MAX;
            else
                dp[i] = 1 + x;
        }
        return dp[amount]>=INT_MAX?-1:dp[amount];
    }
    int dp(vector<int>& coins, int amts) {
        if (amts < 0) return INT_MAX;
        if (amts == 0) return 0;
        if (mp.find(amts) != mp.end()) return mp[amts];
        int x = INT_MAX;

        for (int i : coins) {
            x = min(x, dp(coins, amts - i));
        }
        if (x == INT_MAX) return mp[amts] = INT_MAX;
        // cout << "amts " << amts << " x " << 1 + x << endl;
        mp[amts] = 1 + x;
        return 1 + x;
    }
};
