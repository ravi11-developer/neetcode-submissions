class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int firstIdx = 0;
        int ans = 0;
        int i = 0;
        while (i+1 < n) {
            while (i + 1 < n && prices[i] >= prices[i + 1]) {i++;}
            firstIdx = i;
            while (i + 1 < n && prices[i] <= prices[i + 1]) {i++;}
            ans += (prices[i] - prices[firstIdx]);
        }
        return ans;
    }
};