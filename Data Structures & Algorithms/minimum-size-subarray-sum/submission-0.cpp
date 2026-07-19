class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans=INT_MAX;
        int sum=0;
        int l=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            while(sum>=target){
                ans=min(ans,i-l+1);
                sum-=nums[l];
                l++;
            }
        }
        return ans==INT_MAX?0:ans;
    }
};