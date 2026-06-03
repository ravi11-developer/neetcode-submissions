class Solution {
    map<int, int> mp;

   public:
    int numDecodings(string s) {
        mp.clear();
        int n = s.length();
        vector<int> dp(n + 1, 0);
        dp[n] = 1;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '0')
                dp[i] = 0;
            else {
                dp[i] += dp[i + 1];
                if (i + 1 < n) {
                    int x = (s[i] - '0') * 10 + (s[i + 1] - '0');
                    if (x >= 10 && x <= 26) dp[i] += dp[i + 2];
                }
            }
        }
        return dp[0];
        // return dp(s, 0);
    }
    int dp(string s, int idx) {
        if (idx >= s.length()) return 1;
        if (s[idx] == '0') return 0;
        int s1 = 0, s2 = 0;
        if (mp.find(idx) != mp.end()) return mp[idx];
        s1 = dp(s, idx + 1);
        if (idx != s.length() - 1) {
            string temp = s.substr(idx, 2);
            int x = stoi(temp);
            if (x >= 10 && x <= 26) s2 = dp(s, idx + 2);
        }
        mp[idx] = s1 + s2;
        return s1 + s2;
    }
};
