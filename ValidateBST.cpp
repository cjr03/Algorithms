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
    bool isValidBST(TreeNode* root) {
        return isBSTValid(root, LONG_MIN, LONG_MAX);
    }

    bool isBSTValid(TreeNode* root, long min, long max){
        if (!root) return true;
        else if (root->val <= min || root->val >= max) return false;
        else return isBSTValid(root->left, min, root->val) && isBSTValid(root->right, root->val, max);
    }
};
