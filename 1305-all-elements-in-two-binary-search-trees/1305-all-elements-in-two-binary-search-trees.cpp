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
    void inorderTraversal(TreeNode* root, vector<int> &v){
        if(root == NULL) return;
        
        inorderTraversal(root->left,v);
        v.push_back(root->val);
        inorderTraversal(root->right,v);  
    }
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> values1;
        vector<int> values2;
        
        vector<int> ans;
        
        inorderTraversal(root1, values1);
        inorderTraversal(root2, values2);
        
        int ptr1=0,ptr2=0;
        int n1=values1.size();
        int n2=values2.size();

        while(ptr1 < n1 || ptr2 < n2){
            int num1= (ptr1 < n1)? values1[ptr1]: INT_MAX;
            int num2= (ptr2 < n2)? values2[ptr2]: INT_MAX;
            
            if(num1 < num2){
                ans.push_back(num1);
                ptr1++;
            }else{
                ans.push_back(num2);
                ptr2++;
            }
        }
        
        return ans;
            

        
    }
};