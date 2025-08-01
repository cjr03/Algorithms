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
    int sumNumbers(TreeNode* root) {
        if (!root) return 0;
        int sum = 0;
        stack<pair<TreeNode*, int>> s;
        s.push({root, root->val});
        while(!s.empty()){
            TreeNode* cur = s.top().first;
            int num = s.top().second;
            s.pop();
            if(!cur->left && !cur->right) sum += num;
            if(cur->left) s.push({cur->left, num * 10 + cur->left->val});
            if(cur->right) s.push({cur->right, num * 10 + cur->right->val});
            
        }
        return sum;
    }
};
