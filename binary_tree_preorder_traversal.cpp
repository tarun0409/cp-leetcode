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
    vector<int> preorderTraversal(TreeNode* root) {
        
        vector<int> result;
        if(root == NULL)
        {
            return result;
        }
        stack<TreeNode *> s;
        s.push(root);
        while(!s.empty())
        {
            TreeNode * curr_node = s.top();
            s.pop();
            result.push_back(curr_node->val);
            if(curr_node->right != NULL)
            {
                s.push(curr_node->right);
            }
            if(curr_node->left != NULL)
            {
                s.push(curr_node->left);
            }
        }
        return result;
        
    }
};
