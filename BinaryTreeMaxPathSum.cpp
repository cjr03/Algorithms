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
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        maxSumRec(root, maxSum);
        return maxSum;
    }
private:
    int maxSumRec(TreeNode* root, int & maxSum) {
        if(!root) return 0;
        int left = max(maxSumRec(root->left, maxSum), 0);
        int right = max(maxSumRec(root->right, maxSum), 0);
        int sum = root->val + left + right;
        maxSum = max(maxSum, sum);
        return root->val + max(left, right);
    }
};
