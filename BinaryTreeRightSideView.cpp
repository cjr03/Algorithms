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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> results;
        if (!root) return results;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int width = q.size();
            for(int i = 1; i <= width; ++i){
                TreeNode* cur = q.front();
                q.pop();
                if(i == width) results.push_back(cur->val);
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
            }
        }
        return results;
    }
    
};
