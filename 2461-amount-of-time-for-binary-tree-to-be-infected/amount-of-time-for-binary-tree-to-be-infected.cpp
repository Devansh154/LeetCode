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
    TreeNode* NodeToMap(TreeNode* root,int start , map<TreeNode* , TreeNode* > &mp){
        queue<TreeNode*> q;
        TreeNode* res = NULL;
        q.push(root);
        mp[root] = NULL;
        while(!q.empty()){
            TreeNode* front = q.front();
            q.pop();
            if(front -> val == start){
                res = front;
            }
            if(front -> left){
                mp[front-> left] = front;
                q.push(front -> left);
            }
            if(front -> right){
                mp[front -> right] = front;
                q.push(front -> right);
            }
        }
        return res;
    }
    int burn(TreeNode* root, map<TreeNode*, TreeNode*> &mp){
        map<TreeNode* ,bool> visited;
        queue<TreeNode*> q;
        q.push(root);
        visited[root] = 1;

        int ans = 0;
        while(!q.empty()){
            int size = q.size();
            bool flag = 0;
            for(int i = 0; i < size; i++){
                TreeNode* front = q.front();
                q.pop();

                if(front -> left && !visited[front -> left]){
                    flag = 1;
                    q.push(front -> left);
                    visited[front -> left] = 1;
                }
                if(front -> right && !visited[front -> right]){
                    flag = 1;
                    q.push(front -> right);
                    visited[front -> right] = 1;
                }
                if(mp[front] && !visited[mp[front]]){
                    flag = 1;
                    q.push(mp[front]);
                    visited[mp[front]] = 1;
                }
            }
            if(flag == 1){
                ans++;
            }
        }
        return ans;

    }
    int amountOfTime(TreeNode* root, int start) {
        map<TreeNode* , TreeNode*> mp;
        TreeNode* target = NodeToMap(root, start, mp);
        int ans = burn(target, mp);

        return ans;
    }
};