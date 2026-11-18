
class Solution {
public:
    bool solve(TreeNode* root, long long min, long long max) {

        if (root == NULL) {
            return true;
        }

        if (root->val <= min || root->val >= max) {
            return false;
        }

        bool leftv = solve(root->left, min, root->val);

        bool rightv = solve(root->right, root->val, max);

        return leftv && rightv;
    }

    bool isValidBST(TreeNode* root) {
        return solve(root, LLONG_MIN, LLONG_MAX);
    }
};
