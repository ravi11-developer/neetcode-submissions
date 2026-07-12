class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int>ans;
        for(int i=0;i<asteroids.size();i++){
            bool f=true;
            while(ans.size()!=0&&ans[ans.size()-1]*asteroids[i]<0&&ans[ans.size()-1]>0){
                int x=abs(ans[ans.size()-1]);
                int y=abs(asteroids[i]);
                if(x==y){
                    ans.pop_back();
                    f=false;
                    break;
                }else if(x<y){
                    ans.pop_back();
                }else{
                    f=false;
                    break;
                }
            }
            if(f){
                ans.push_back(asteroids[i]);
            }
        }
        return ans;
    }
};