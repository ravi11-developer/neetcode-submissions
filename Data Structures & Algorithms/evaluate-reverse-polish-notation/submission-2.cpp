class Solution {
   public:
    int evalRPN(vector<string>& tokens) {
        stack<string> s;
        for (string str : tokens) {
            if (str == "+") {
                auto [t1, t2] = utility(s);
                int x = t1 + t2;
                cout << "+ " << x << endl;
                s.push(to_string(x));
            } else if (str == "-") {
                auto [t1, t2] = utility(s);
                int x = t2 - t1;
                cout << "- " << t1 << " " << t2 << endl;
                cout << "- " << x << endl;
                s.push(to_string(x));
            } else if (str == "*") {
                auto [t1, t2] = utility(s);
                int x = t1 * t2;
                cout << "* " << x << endl;
                s.push(to_string(x));
            } else if (str == "/") {
                auto [t1, t2] = utility(s);
                int x = t2 / t1;
                cout << "/ " << x << endl;
                s.push(to_string(x));
            } else {
                s.push(str);
            }
        }
        return stoi(s.top());
    }

   private:
    pair<int, int> utility(stack<string>& s) {
        int t1 = stoi(s.top());
        s.pop();
        int t2 = stoi(s.top());
        s.pop();
        return {t1, t2};
    }
};
