class Solution {
public:
    long long minEnd(int n, int x) {
        long long ans=0;
        int num=n-1;
        int shift=0;
        while(num!=0||x!=0){
            long long y=x&1;
            long long z=num&1;

            if(y==1){
                ans+=(1<<shift);
                shift++;
                x=(x>>1);
            }else{
                ans+=((y|z)<<shift);
                shift++;
                x=(x>>1);
                num=(num>>1);
            }
        }
        return ans;
    }
};