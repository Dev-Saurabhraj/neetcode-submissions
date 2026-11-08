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
int solve(TreeNode* root, int maxi){
    if(root==NULL) return 0;

    int count = 0;
    if(root->val >= maxi){
        count++;
    }

    int max1 = max(maxi, root->val);
    int left = solve(root->left,max1);
    int right = solve(root->right,max1);

    return count+ left + right;
}


class Solution {
public:
    int goodNodes(TreeNode* root) {
    return solve(root, root->val);
        
    }
};
