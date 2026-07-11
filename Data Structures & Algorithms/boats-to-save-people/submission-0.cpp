class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int l=0;
       int r=people.size()-1;
        int ans=0;
        while(l<=r){
            int sum;
            if(l==r){
                sum=people[l];
            }else
            sum=people[l]+people[r];
            if(sum<=limit){
                l++;
                r--;
            }else{
                r--;
            }
            ans++;
        }
        return ans;
    }
};