class Solution {
    vector<int>v;
public:
    int subsetXORSum(vector<int>& nums) {
        v=nums;
        return f(0,0);
    }
    int f(int idx, int x){
        if(idx==v.size()) return x;
        return f(idx+1,x^v[idx])+f(idx+1,x);
    }
};