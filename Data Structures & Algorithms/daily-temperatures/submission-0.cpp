class Solution {
   public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<int> s;
        //  int i=n-1;
        vector<int> ans(n);
        s.push(temperatures[n - 1]);
        ans[n-1]=0;
        for (int i = n - 2; i >= 0; i--) {
            int x = temperatures[i];
            int idx = 0;
            stack<int> temp;
            while (!s.empty() && s.top() <= x) {
                cout<<s.top()<<endl;
                temp.push(s.top());
                s.pop();
                idx++;
            }
            if (s.empty() == true) {
                ans[i] = 0;
            } else {
                ans[i] = ++idx;
            }
            while (!temp.empty()) {
                s.push(temp.top());
                temp.pop();
            }
            s.push(x);
        }
        return ans;
    }
};
