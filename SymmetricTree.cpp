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
        if (p == nullptr && q == nullptr) {
            return true;
        } else if (p == nullptr || q == nullptr) {
            return false;
        } else if (p->val != q->val) {
            return false; 
        } else {
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        }
    }
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
    bool isSymmetric(TreeNode* root) {
        return isSameTree(root->left, invertTree(root->right));
    }
};
