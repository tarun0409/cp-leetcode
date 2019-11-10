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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root == NULL)
        {
            return result;
        }
        queue<TreeNode *> q;
        queue<int> nums;
        q.push(root);
        nums.push(1);
        while(!q.empty())
        {
            int p = 0;
            int n = nums.front();
            nums.pop();
            vector<int> level;
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
            result.push_back(level);
            nums.push(p);
            
        }
        return result;
        
    }
};
