
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});

        long long maxWidth = 0;

        while (!q.empty()) {
            int levelSize = q.size();

            // Index of the first node at this level
            long long baseIndex = q.front().second;

            long long firstIndex = 0;
            long long lastIndex = 0;

            for (int i = 0; i < levelSize; i++) {
                auto current = q.front();
                q.pop();

                TreeNode* node = current.first;
                long long index = current.second - baseIndex;

                if (i == 0) {
                    firstIndex = index;
                }

                if (i == levelSize - 1) {
                    lastIndex = index;
                }

                if (node->left != nullptr) {
                    q.push({
                        node->left,
                        2 * index + 1
                    });
                }

                if (node->right != nullptr) {
                    q.push({
                        node->right,
                        2 * index + 2
                    });
                }
            }

            long long width =
                lastIndex - firstIndex + 1;

            maxWidth = max(maxWidth, width);
        }

        return static_cast<int>(maxWidth);
    }
};
