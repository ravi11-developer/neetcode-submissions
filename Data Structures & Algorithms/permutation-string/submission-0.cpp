class Solution {
   public:
    bool checkInclusion(string s1, string s2) {
        vector<int> freq(26, 0);
        for (char i : s1) {
            freq[i - 'a']++;
        }
        vector<int> tempFreq(26, 0);
        int l = 0;
        for (int r = 0; r < s2.length(); r++) {
            tempFreq[s2[r] - 'a']++;
            while ((r - l + 1) > s1.length()) {
                tempFreq[s2[l] - 'a']--;
                l++;
            }
            if ((r - l + 1) == s1.length()) {
                bool check = true;
                for (int i = 0; i < 26; i++) {
                    if (freq[i] != tempFreq[i]) {
                        check = false;
                        break;
                    }
                }
                if (check) return true;
            }
        }
        return false;
    }
};
