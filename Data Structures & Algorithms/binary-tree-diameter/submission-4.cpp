class Solution {
public:
    int ans = 0;

    int height(TreeNode* root) {
        if (!root)
            return 0;

        int left = height(root->left);
        int right = height(root->right);

        // Number of edges in the path through this node
        ans = max(ans, left + right);

        // Height in number of nodes
        return 1 + max(left, right);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return ans;
    }
};