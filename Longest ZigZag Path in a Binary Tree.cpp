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

int maxi =0;

void res(TreeNode *root, int dir, int len){
    if(root==NULL){
        return;
    }

    maxi = max(maxi,len);

    if(dir == 0){
        res(root->left,dir,1);
        res(root->right,dir^1,len+1);
    }

    else{
        res(root->left,dir^1,len+1);
        res(root->right,dir,1);
    }

    return;
}
    int longestZigZag(TreeNode* root) {
        res(root->left,0,1);
        res(root->right,1,1);
        return maxi;
    }
};
