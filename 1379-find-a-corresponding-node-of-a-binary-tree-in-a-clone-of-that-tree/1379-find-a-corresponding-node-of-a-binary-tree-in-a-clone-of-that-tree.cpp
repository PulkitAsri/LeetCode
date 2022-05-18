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
    void recurr(TreeNode* &ans, TreeNode* original, TreeNode* cloned, TreeNode* target ){
        
        if(original == NULL) return;
        
        if(original == target){
            ans= cloned;
            return;
        }
        recurr(ans, original->left, cloned->left, target);
        recurr(ans, original->right, cloned->right, target);
    }
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        TreeNode* ans= NULL;
        recurr(ans, original, cloned, target);
        return ans;
    }
};