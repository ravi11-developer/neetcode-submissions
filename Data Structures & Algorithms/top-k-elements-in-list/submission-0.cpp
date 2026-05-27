class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> freq;
        for (int i : nums) freq[i]++;
        vector<vector<int>> bucket(nums.size() + 1);
        for (auto i : freq) {
            int n = i.first;
            int c = i.second;
            bucket[c].push_back(n);
        }
        vector<int> res;
        for (int i = nums.size(); i >= 0; i--) {
            for (int j : bucket[i]) {
                res.push_back(j);
                if (res.size() == k) {
                    break;
                }
            }
            if (res.size() == k) {
                break;
            }
        }
        return res;
    }
};
