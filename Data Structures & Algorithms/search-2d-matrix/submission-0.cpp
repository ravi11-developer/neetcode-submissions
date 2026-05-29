class Solution {
   public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix[0].size();
        // cout<<matrix.size()<<matrix[0].size()<<endl;
        for (int i = 0; i < matrix.size(); i++) {
            if (matrix[i][0] <= target && target <= matrix[i][n - 1]) {
                cout << matrix[i][0] << " " << target << " " << matrix[i][n - 1] << endl;
                int l = 0;
                int r = n - 1;
                while (l <= r) {
                    int mid = l + (r - l) / 2;
                    // cout << i << " " << mid << " " << matrix[i][mid] << endl;
                    if (matrix[i][mid] == target)
                        return true;
                    else if (matrix[i][mid] < target) {
                        l = mid + 1;
                    } else {
                        r = mid - 1;
                    }
                }
            }
        }
        return false;
    }
};
