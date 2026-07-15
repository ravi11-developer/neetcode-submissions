class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>edges(numCourses);
        vector<int>indegree(numCourses,0);
        for(auto i:prerequisites){
            edges[i[1]].push_back(i[0]);
            indegree[i[0]]++;
        }
        vector<int>ans;
        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
                ans.push_back(i);
            }
        }
        while(!q.empty()){
            int x=q.front();
            q.pop();
            for(int i:edges[x]){
                indegree[i]--;
                if(indegree[i]==0){
                    ans.push_back(i);
                    q.push(i);
                }
            }
        }
        if(ans.size()!=numCourses) return {};
        return ans;
    }
};
