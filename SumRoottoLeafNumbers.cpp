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
    int sumNumbers(TreeNode* root) {

        if(!root){
            return 0;
        }

        int result =0;
        sum(root,0,result);
        return result;

        
    }


    void sum(TreeNode* root, int val, int& result){
        int curr = val*10 + root->val;

        if(!root->left && !root->right){
            result += curr;
            return;

        }

        if(root->left){
            sum(root->left, curr,result);
            
        }

        if(root->right){
            sum(root->right, curr, result);
        }
    }
};
