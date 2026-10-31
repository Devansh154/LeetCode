class Solution {
public:
    unordered_map<int, int> mp;
    int preIndex = 0;

    TreeNode* buildTree(vector<int>& preorder,
                        vector<int>& inorder) {

        // Store inorder values and their indices
        for (int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }

        preIndex = 0;

        return solve(preorder, 0, inorder.size() - 1);
    }

    TreeNode* solve(vector<int>& preorder,
                    int inStart, int inEnd) {

        // No nodes in this subtree
        if (inStart > inEnd) {
            return nullptr;
        }

        // First element in preorder is the root
        int rootValue = preorder[preIndex++];

        TreeNode* root = new TreeNode(rootValue);

        // Find root position in inorder
        int inIndex = mp[rootValue];

        // Construct left subtree
        root->left = solve(preorder,
                          inStart, inIndex - 1);

        // Construct right subtree
        root->right = solve(preorder,
                           inIndex + 1, inEnd);

        return root;
    }
};