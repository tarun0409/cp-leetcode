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
    void invertTreeUtil(TreeNode * curr_node)
    {
        if(curr_node == NULL)
        {
            return;
        }
        invertTreeUtil(curr_node->left);
        invertTreeUtil(curr_node->right);
        TreeNode * temp_node = curr_node->left;
        curr_node->left = curr_node->right;
        curr_node->right = temp_node;
    }
    TreeNode* invertTree(TreeNode* root) {
        invertTreeUtil(root);
        return root;
    }
};
