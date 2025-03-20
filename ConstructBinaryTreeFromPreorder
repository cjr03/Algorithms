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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> inMap;
        for (int i = 0; i < inorder.size(); i++) {
            inMap[inorder[i]] = i;
        }
        int postIndex = postorder.size() - 1;
        return helper(inorder, postorder, 0, inorder.size() - 1, postIndex, inMap);
    }
    
private:
    TreeNode* helper(vector<int>& inorder, vector<int>& postorder, int inStart, int inEnd,
                       int &postIndex, unordered_map<int, int>& inMap) {
        if (inStart > inEnd) {
            return nullptr;
        }
        int rootVal = postorder[postIndex--];
        TreeNode* root = new TreeNode(rootVal);
        int inIndex = inMap[rootVal];
        root->right = helper(inorder, postorder, inIndex + 1, inEnd, postIndex, inMap);
        root->left  = helper(inorder, postorder, inStart, inIndex - 1, postIndex, inMap);
        return root;
    }
};
