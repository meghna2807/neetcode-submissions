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
    void helper(TreeNode* root,int maxSoFar,int &cnt){
        if(root == NULL) return;
        
        if(root->val>=maxSoFar){
            cnt++;
            maxSoFar = root->val;
        }

        helper(root->left,maxSoFar,cnt);
        helper(root->right,maxSoFar,cnt);
    }
    int goodNodes(TreeNode* root) {
        int cnt = 0;
        helper(root,INT_MIN,cnt);
        return cnt;
    }
};
