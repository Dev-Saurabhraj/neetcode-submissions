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
    unordered_map<int, int> mp;

    TreeNode* solve(vector<int> & preorder, int start, int end, int pStart){
        if(start > end) return nullptr;

        TreeNode* root = new TreeNode(preorder[pStart]);
        int mid = mp[root->val];
        int leftSize = mid - start;

        root->left = solve(preorder, start, mid-1, pStart+1);

        root->right = solve(preorder , mid+1, end, pStart+ leftSize +1 );

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        int n = inorder.size();

        for(int i = 0; i<n; i++){
            mp[inorder[i]] = i;
        }

        return solve(preorder, 0, n-1, 0);
    }
};
