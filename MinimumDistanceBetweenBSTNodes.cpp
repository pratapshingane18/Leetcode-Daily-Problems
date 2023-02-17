// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */

class Solution {
public:
    int minDiffInBST(TreeNode* root) {
        int minDiff = INT_MAX;
        int prevVal = INT_MIN;
        traverse(root, minDiff, prevVal);
        return minDiff;
    }
    
    void traverse(TreeNode* root, int& minDiff, int& prevVal) {
        if (root == NULL) {
            return;
        }
        traverse(root->left, minDiff, prevVal);
        if (prevVal != INT_MIN) {
            minDiff = min(minDiff, root->val - prevVal);
        }
        prevVal = root->val;
        traverse(root->right, minDiff, prevVal);
    }
};






// class Solution {
// public:

//     int minDiffInBST(TreeNode* root) {
      
//       vector<int> v;
//     if (root == NULL) {
//         return 0;
//     }
//     minDiffInBST(root->left);
//     v.push_back(root->val);
//     minDiffInBST(root->right);

        
    

//     sort(v.begin(), v.end());

//     int currmin = 0;
//     int Min =v[1] = v[0];

//     for(int i =0; i < v.size() -2; i++){
//         currmin = v[i+1] - v[i];

//         if(currmin < Min){
//             Min = currmin;
//         }
//     }

//     return Min;
//     }


// };
