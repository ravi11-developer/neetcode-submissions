class Solution {
    vector<int>stone;
    map<int,int>mp;
public:
    string stoneGameIII(vector<int>& stoneValue) {
        stone=stoneValue;
        mp.clear();
        long long x=func(0);
        if(x>0){
            return "Alice";

        }else if(x<0){
            return "Bob";
        }else  return "Tie";
    }
    long  long func(int idx){
        int n=stone.size();
        if(idx>=n) return 0;
        if(mp.find(idx)!=mp.end()) return mp[idx];
        long long  res=LLONG_MIN;
        long long a=0,b=0,c=0;
        a=stone[idx];
        if(idx+1<n) b=stone[idx+1];
        if(idx+2<n) c=stone[idx+2];

        res=max(res,a-func(idx+1));
        res=max(res,a+b-func(idx+2));
        res=max(res,a+b+c-func(idx+3));
        return mp[idx]=res;
    }
};