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
    int ans=0;
    int findTilt(TreeNode* root) {
        ans=0;
        DFS(root);
        return ans;
    }
    
    int DFS(TreeNode* root){
        //base case
        if(!root) return 0;
        
        int leftSum=DFS(root->left);
        int rightSum=DFS(root->right);
        
        ans+= abs(rightSum-leftSum);
        return rightSum + leftSum + root->val;
    }
};