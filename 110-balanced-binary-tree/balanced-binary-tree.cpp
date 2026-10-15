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
    int checkBalance(TreeNode* root){
        if(root == nullptr){
            return 0;
        }
        int leftTree = checkBalance(root -> left);
        if(leftTree == -1){
            return -1;
        }
        int rightTree = checkBalance(root -> right);
        if(rightTree == -1){
            return -1;
        }
        if(abs(leftTree - rightTree) > 1){
            return -1;
        }
        return 1 + max(leftTree , rightTree);
    }
    bool isBalanced(TreeNode* root) {
        return checkBalance(root) != -1;
    }
};