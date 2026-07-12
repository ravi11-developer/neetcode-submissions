class Solution {
    vector<vector<int>>ans;
    vector<int>v;
public:

    vector<vector<int>> subsets(vector<int>& nums) {
        v=nums;
        vector<int>temp;
        func(0,temp);
        return ans;
    }
    void func(int idx,vector<int>temp){
        if(idx==v.size()) {
            ans.push_back(temp);
            return;
        }
        func(idx+1,temp);
        temp.push_back(v[idx]);
        func(idx+1,temp);
    }
    
    
};
