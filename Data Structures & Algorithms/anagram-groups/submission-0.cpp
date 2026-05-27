class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // vector<pair<string,string>>str;
        unordered_map<string, vector<string>> mp;
        for (string s : strs) {
            string k = s;
            sort(k.begin(), k.end());
            mp[k].push_back(s);
        }
        vector<vector<string>> ans;
        for (auto i : mp) {
            // cout<<<<" "
            ans.push_back(i.second);
        }
        return ans;
    }
};
