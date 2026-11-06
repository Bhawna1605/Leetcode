class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root == NULL) return res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int lvlsize = q.size();
            vector<int>tmp;
            while(lvlsize--) {
                TreeNode* t = q.front();
                q.pop();
                tmp.push_back(t->val);
                if(t->left != NULL) {
                    q.push(t->left);
                }
                if(t->right != NULL) {
                    q.push(t->right);
                }
            }
            res.push_back(tmp);
        }
        return res;
    }
};