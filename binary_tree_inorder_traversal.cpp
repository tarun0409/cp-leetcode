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
    vector<int> inorderTraversal(TreeNode* root) {
        
        stack<TreeNode *> s;
        vector<int> result;
        if(root == NULL)
        {
            return result;
        }
        TreeNode * curr = root;
        while(curr!=NULL || !s.empty())
        {
            if(curr == NULL)
            {
                TreeNode * n = s.top();
                s.pop();
                result.push_back(n->val);
                curr = n->right;
            }
            else
            {
                s.push(curr);
                curr = curr->left;
            }
        }
        return result;
    }
};
