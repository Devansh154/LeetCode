class Solution {
public:
    void lefftt(TreeNode* root, vector<int>& ans, int level) {
        if (root == NULL) {
            return;
        }

        if (level == ans.size()) {
            ans.push_back(root->val);
        }

        lefftt(root->left, ans, level + 1);
        lefftt(root->right, ans, level + 1);
    }

    int findBottomLeftValue(TreeNode* root) {
        vector<int> ans;

        lefftt(root, ans, 0);

        return ans.back();
    }
};