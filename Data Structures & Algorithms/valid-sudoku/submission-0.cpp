class Solution {
   public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < board.size(); i++) {
            set<char> s;
            for (int j = 0; j < board[0].size(); j++) {
                if (s.find(board[i][j]) != s.end()&&board[i][j]!='.') {
                    cout<<i<<" "<<j<<" "<<board[i][j]<<endl;
                    cout << "Row Error\n";
                    return false;
                }

                s.insert(board[i][j]);
            }
        }
        for (int i = 0; i < board[0].size(); i++) {
            set<char> s;
            for (int j = 0; j < board.size(); j++) {
                if (s.find(board[j][i]) != s.end()&&board[j][i]!='.') {
                    cout << "Colo Error\n";
                    return false;
                }
                s.insert(board[j][i]);
            }
        }
        for (int i = 0; i < board.size(); i += 3) {
            for (int j = 0; j < board[0].size(); j += 3) {
                set<char> s;
                for (int k = i; k < i + 3; k++) {
                    for (int l = j; l < j + 3; l++) {
                        if (s.find(board[k][l]) != s.end()&&board[k][l]!='.') {
                            cout << "3d Block Error\n";
                            return false;
                        }
                        s.insert(board[k][l]);
                    }
                }
            }
        }
        return true;
    }
};
