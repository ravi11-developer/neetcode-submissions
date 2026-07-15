class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>edges(numCourses);
        vector<int>indegree(numCourses,0);
        for(auto i:prerequisites){
            edges[i[1]].push_back(i[0]);
            indegree[i[0]]++;
        }
        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0) q.push(i);
        }
        int cnt=0;
        while(!q.empty()){
            int x=q.front();
            q.pop();
            cnt++;
            for(int neighbour:edges[x]){
                indegree[neighbour]--;
                if(indegree[neighbour]==0) q.push(neighbour);
            }
        }
        return cnt==numCourses;
    }
};
