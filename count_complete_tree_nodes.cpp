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
    int countNodes(TreeNode* root) {
        
        queue<TreeNode *> q;
        int result = 0;
        if(root == NULL)
        {
            return result;
        }
        q.push(root);
        while(!q.empty())
        {
            TreeNode * t = q.front();
            q.pop();
            result++;
            if(t->left != NULL)
            {
                q.push(t->left);
            }
            if(t->right != NULL)
            {
                q.push(t->right);
            }
        }
        return result;
        
    }
};
