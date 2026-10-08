class Solution {
private:
    unordered_map<int, int> pos;

    TreeNode* solve(vector<int>& preorder, int preStart, int preEnd,
                    vector<int>& inorder, int inStart, int inEnd) {

        // No nodes in this subtree
        if (preStart > preEnd || inStart > inEnd)
            return nullptr;

        // First element of preorder is the root
        int rootValue = preorder[preStart];
        TreeNode* root = new TreeNode(rootValue);

        // Find root position in inorder
        int inRoot = pos[rootValue];

        // Number of nodes in left subtree
        int leftSize = inRoot - inStart;

        // Build left subtree
        root->left = solve(preorder, preStart + 1, preStart + leftSize, inorder,
                           inStart, inRoot - 1);

        // Build right subtree
        root->right = solve(preorder, preStart + leftSize + 1, preEnd, inorder,
                            inRoot + 1, inEnd);

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        // Store inorder value -> index
        for (int i = 0; i < inorder.size(); i++) {
            pos[inorder[i]] = i;
        }

        return solve(preorder, 0, preorder.size() - 1, inorder, 0,
                     inorder.size() - 1);
    }
};