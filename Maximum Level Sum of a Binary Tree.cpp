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
    int dfs[10000] = {0};
    int max_traverse = -1;
  
    void findDepthSum(TreeNode* root, int d) {
        if (root==NULL)
            return;
        dfs[d] += root->val;
        findDepthSum(root->left,d+1);
        findDepthSum(root->right,d+1);
        
        if (d > max_traverse)
            max_traverse = d;
    }
    
    
    int maxLevelSum(TreeNode* root) {

	findDepthSum(root,1);
	int maxSum = INT_MIN;
	int levelIdx = -1;
	for(int i=1;i<=max_traverse;++i) {
		cout << dfs[i] << " ";
		if (maxSum < dfs[i]) {
			maxSum = dfs[i];
			levelIdx = i;
		}
	}
	return levelIdx;
}
};
