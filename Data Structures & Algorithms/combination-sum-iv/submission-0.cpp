class Solution {
    map<int,int>mp;
public:
    int combinationSum4(vector<int>& nums, int target) {
        mp.clear();
        return (int)f(target,nums);
    }
    private:
    long long  f(int t,vector<int>&n){
        if(t<0) return 0;
        if(t==0) return 1;
        if(mp.find(t)!=mp.end()) return mp[t];
        long long res=0;
        for(int i=0;i<n.size();i++){
            res+=f(t-n[i],n);
        }
        return mp[t]=res;
    }
};