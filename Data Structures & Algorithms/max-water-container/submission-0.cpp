class Solution {
   public:
    int maxArea(vector<int>& heights) {
        int mx = INT_MIN;
        int left = 0;
        int right = heights.size()-1;
        while (left < right) {
            int waterTrapped = min(heights[left], heights[right]) * (right - left);
            mx = max(mx, waterTrapped);
            if(heights[left]<heights[right]) left++;
            else right--;
        }
        return mx;
    }
};
