class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int zor=0;
        for(int i:nums) zor=zor^i;
        return zor;
    }
};
