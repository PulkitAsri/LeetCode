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

#define ll unsigned long long int
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, ll>>q;
        q.push({root,0});
        q.push({NULL,0});
        ll maxi=1;
        while(!q.empty()){
            auto [ptr,n]=q.front();
            if(ptr==NULL){
                q.pop();
                
                if(q.size()){
                    auto [ptr1,x]=q.front();
                    auto [ptr2,y]=q.back();
                    maxi=max(y-x+1,maxi);
                    q.push({NULL,0});
                }
                continue;
            }
            
            if(ptr->left)
                q.push({ptr->left,2ll*n});
            if(ptr->right)
                q.push({ptr->right,2ll*n+1});
            q.pop();
        }
        return maxi;
    }
};