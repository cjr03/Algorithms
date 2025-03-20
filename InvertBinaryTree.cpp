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
    TreeNode* invertTree(TreeNode* root) {
        if(root == nullptr){
            return nullptr;
        }
        TreeNode* newNode = new TreeNode(root->val, root->right, root->left);
        if(newNode->left != nullptr) {
            newNode->left = invertTree(newNode->left);
        }
        if(newNode->right != nullptr){
            newNode->right = invertTree(newNode->right);
        }
        return newNode;
    }
};
