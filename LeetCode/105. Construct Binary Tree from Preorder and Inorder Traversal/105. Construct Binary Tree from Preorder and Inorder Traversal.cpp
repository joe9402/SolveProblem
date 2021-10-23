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
    void dfs(vector<int>& preorder,int preL,int preR,vector<int>& inorder,int inL,int inR,TreeNode* now){
        if(preR-preL <= 1){
            now->right = nullptr;
            now->left = nullptr;
            return;
        }
        for(int i = 0;i<inR-inL;i++){
            if(now->val == inorder[inL+i]){
                if(i != 0){
                    TreeNode* left = new TreeNode(preorder[preL+1]);
                    now->left = left;
                    dfs(preorder,preL+1,preL+i+1,inorder,inL,inL+i,left);     
                }
                    
                if(inL+i+1 < inR){
                    TreeNode* right = new TreeNode(preorder[preL+i+1]);
                    now->right = right;
                    dfs(preorder,preL+i+1,preR,inorder,inL+(i+1),inR,right);
                }
                break;
            }
        }
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* now;
        now = new TreeNode(preorder[0]);
        dfs(preorder,0,preorder.size(),inorder,0,inorder.size(),now);
        return now;
    }
};