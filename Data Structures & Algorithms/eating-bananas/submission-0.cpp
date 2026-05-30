class Solution {
   public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());

        while (l < r) {
            int mid = l + (r - l) / 2;

            long long time = 0;
            for (int p : piles) {
                time += (p + mid - 1) / mid;
            }

            if (time <= h) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }

        return l;
    }
};