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
    void ino(TreeNode* root,bool &ans,TreeNode* &prev){
        if(root == NULL) return;   

        ino(root->left,ans,prev);
        if(prev == NULL) {
            prev = root;
        } 
        else{
            if(root->val <= prev->val){
                ans = false;
                return;
            }
            prev = root;
        }

        ino(root->right,ans,prev);
    }
    bool isValidBST(TreeNode* root) {
        bool ans = true;
        TreeNode* prev = NULL;
        ino(root,ans,prev);
        return ans;
    }
};
