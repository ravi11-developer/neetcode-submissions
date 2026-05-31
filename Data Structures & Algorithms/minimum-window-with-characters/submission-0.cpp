class Solution {
   public:
    string minWindow(string s, string t) {
        vector<int> lower(26, 0);
        vector<int> upper(26, 0);

        for (char c : t) {
            if (c >= 'A' && c <= 'Z')
                upper[c - 'A']++;
            else
                lower[c - 'a']++;
        }

        vector<int> templower(26, 0);
        vector<int> tempupper(26, 0);

        int l = 0;
        string minString = "";

        for (int r = 0; r < s.size(); r++) {
            if (s[r] >= 'A' && s[r] <= 'Z')
                tempupper[s[r] - 'A']++;
            else
                templower[s[r] - 'a']++;

            bool valid = true;

            for (int i = 0; i < 26; i++) {
                if (templower[i] < lower[i] || tempupper[i] < upper[i]) {
                    valid = false;
                    break;
                }
            }

            while (valid) {
                if (minString.empty() || r - l + 1 < minString.size()) {
                    minString = s.substr(l, r - l + 1);
                }

                if (s[l] >= 'A' && s[l] <= 'Z')
                    tempupper[s[l] - 'A']--;
                else
                    templower[s[l] - 'a']--;

                l++;

                valid = true;

                for (int i = 0; i < 26; i++) {
                    if (templower[i] < lower[i] || tempupper[i] < upper[i]) {
                        valid = false;
                        break;
                    }
                }
            }
        }

        return minString;
    }
};