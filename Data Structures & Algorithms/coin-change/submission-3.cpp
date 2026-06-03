class Solution {
    map<int, int> mp;

   public:
    int coinChange(vector<int>& coins, int amount) {
        mp.clear();

        int x = dp(coins, amount);
        // cout<<"x "<<x<<endl;
        if (x >=INT_MAX) return -1;
        return x;
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
