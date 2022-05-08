/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root,p,q);
        return res;
    }
    
    TreeNode* res = NULL;
    
    bool dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return false;
        bool l = false, r = false, it = false;
        
        if(root -> right != NULL) {
            r = dfs(root->right, p,q);
        }
        if(root -> left != NULL) {
            l = dfs(root->left, p,q);
        }
        if(l && r){
            res = root;
            return true;
        }
        
        if(root->val == p->val || root -> val == q-> val){
            it = true;
            if(l || r) {
                res = root;
            }
        }
        
        return l || r || it;
    }
};