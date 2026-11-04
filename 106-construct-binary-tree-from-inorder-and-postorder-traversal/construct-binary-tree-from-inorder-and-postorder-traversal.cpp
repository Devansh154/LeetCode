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
    unordered_map<int , int > mp;
    int postIndex;
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for(int i = 0; i < inorder.size(); i++){
            mp[inorder[i]] = i;
        }
        postIndex = postorder.size() - 1;
        return solve(postorder, 0, inorder.size() - 1);
    }
    TreeNode* solve(vector<int> &postorder, int inStart,int inEnd){
        if (inStart > inEnd) {
            return nullptr;
        }
        int rootValue = postorder[postIndex--];
        TreeNode* root = new TreeNode(rootValue);

        int index = mp[rootValue];

        root -> right = solve(postorder, index + 1, inEnd);
        root -> left = solve(postorder, inStart, index - 1);

        return root;
    }
};