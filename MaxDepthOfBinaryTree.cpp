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
private:
    struct depthTracker {
        TreeNode* t;
        int ct;
        depthTracker(TreeNode* root, int count){
            t = root;
            ct = ++count;
        }
    };
public:
    int maxDepth(TreeNode* root) {
        if(root == nullptr){
            return 0;
        } else {
            queue<depthTracker*> q;
            q.push(new depthTracker(root, 0));
            int maxCount = 1;
            while(!q.empty()){
                depthTracker *dt = q.front();
                q.pop();
                if(dt->ct > maxCount){
                    maxCount = dt->ct;
                }
                if(dt->t->left != nullptr){
                    q.push(new depthTracker(dt->t->left, dt->ct));
                }
                if(dt->t->right != nullptr){
                    q.push(new depthTracker(dt->t->right, dt->ct));
                }
            }
            return maxCount;
        }
    }
};
