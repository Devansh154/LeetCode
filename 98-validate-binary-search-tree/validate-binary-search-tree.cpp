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
    //Approach : DFS with Bounds

    //Time Complexity = O(n) =>
    /* n is the number of nodes.
    * Each node is visited at most once.
    * Each visit performs constant work: checking bounds and preparing recursive calls.
    * In the worst case, all nodes are checked, so total time is O(n).
    * An invalid node may let us stop early, but the worst-case bound stays O(n).
    */

    //Space Complexity = O(h) =>
    /* h is the height of the tree.
    * Recursive calls use the call stack.
    * At any moment, the stack holds calls along one root-to-leaf path.
    * Balanced tree: h = O(log n) → space is O(log n).
    * Skewed tree: h = O(n) → space is O(n).
    * The left and right subtrees are processed sequentially, so their stack space does not add together.
    */


    bool validate(TreeNode* node, long long lower, long long upper){
        // Step 1: An empty subtree is a valid BST.
        if(node == NULL){
            
            return true;
        }

        // Step 2: Check the restrictions imposed by ALL ancestors.
        // Strict bounds also reject duplicate values.
        if(node->val <= lower || node->val >= upper){
            
            return false;
        }

        // Step 3: Every value in the left subtree must be smaller
        // than this node, while respecting the inherited lower bound.
        if(!validate(node->left, lower, node->val)){
            
            return false;
        }
        
        // Step 4: Every value in the right subtree must be greater
        // than this node, while respecting the inherited upper bound.
        return validate(node->right, node->val, upper);
    }

    bool isValidBST(TreeNode* root) {
        // Step 5: Start with bounds beyond all possible int values.
        // long long allows INT_MIN and INT_MAX to be valid node values.
        return validate(root, LLONG_MIN, LLONG_MAX);
    }
};