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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) return true;
        if((p==nullptr)||(q==nullptr)) return false;
        stack<pair<TreeNode*, TreeNode*>> s;
        s.push({p, q});
        while (!s.empty()) {
            TreeNode* pCurr = s.top().first;
            TreeNode* qCurr = s.top().second;
            s.pop();

            if (pCurr->val != qCurr->val) return false;

            if ((pCurr->left == nullptr) != (qCurr->left == nullptr)) return false;

            if ((pCurr->right == nullptr) != (qCurr->right == nullptr)) return false;

            if (pCurr->left) s.push({pCurr->left, qCurr->left});

            if (pCurr->right) s.push({pCurr->right, qCurr->right});
        }
        return true;
    }
};
