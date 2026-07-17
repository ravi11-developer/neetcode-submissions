/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int goodNodes(TreeNode* root) {
        int mx=INT_MIN,cnt=0;
        solve(root,mx,cnt);
        return cnt;
    }
void solve(TreeNode* root,int mx,int &cnt){
    if(root==nullptr) return ;
    if(root->val>=mx) cnt++;
    mx=max(mx,root->val);
    solve(root->left,mx,cnt);
    solve(root->right,mx,cnt);
    return; 
}

};
