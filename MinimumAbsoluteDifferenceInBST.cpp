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
    int getMinimumDifference(TreeNode* root) {
        if (!root) return 0;
        queue<TreeNode*> q;
        q.push(root);
        vector<int> nums;
        while(!q.empty()){
            TreeNode* cur = q.front();
            q.pop();
            nums.push_back(cur->val);
            if (cur->left) q.push(cur->left);
            if (cur->right) q.push(cur->right);
        }
        sort(nums.begin(), nums.end());
        return minNumsDiff(nums);
    }

    int minNumsDiff(vector<int> nums){
        int nLimit = nums.size();
        int minDiff = INT_MAX;
        for(int n = 1; n < nLimit; ++n){
            int diff = nums[n] - nums[n-1];
            if (diff < minDiff) minDiff = diff;
        }
        return minDiff;
    }
};
