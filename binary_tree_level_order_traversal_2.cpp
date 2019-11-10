/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        
        vector<vector<int>> result;
        if(root == NULL)
        {
            return result;
        }
        queue<TreeNode *> q;
        queue<int> s;
        q.push(root);
        s.push(1);
        while(!q.empty())
        {
            int p = 0;
            vector<int> level;
            int n = s.front();
            s.pop();
            for(int i=0; i<n; i++)
            {
                TreeNode * t = q.front();
                q.pop();
                level.push_back(t->val);
                if(t->left != NULL)
                {
                    q.push(t->left);
                    p++;
                }
                if(t->right != NULL)
                {
                    q.push(t->right);
                    p++;
                }
            }
            s.push(p);
            result.push_back(level);
        }
        reverse(result.begin(),result.end());
        return result;
        
    }
};
