class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) return 0;

        vector<int> alpha(256, 0); 
        int l = 0, mx = 0;

        for (int r = 0; r < s.size(); r++) {
            alpha[s[r]]++;

            while (alpha[s[r]] > 1) {
                alpha[s[l]]--;
                l++;
            }

            mx = max(mx, r - l + 1);
        }

        return mx;
    }
};