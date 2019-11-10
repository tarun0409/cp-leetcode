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
    void insert_node(TreeNode * root, TreeNode * curr_node)
    {
        TreeNode * node = root;
        while(node->left != NULL)
        {
            node = node->left;
        }
        node->left = curr_node;
    }
    void traverse(TreeNode * root, TreeNode * curr_node)
    {
        if(curr_node == NULL)
        {
            return;
        }
        traverse(root, curr_node->left);
        if(curr_node->right != NULL)
        {
            TreeNode * temp_node = curr_node->right;
            curr_node->right = NULL;
            insert_node(root, temp_node);
            traverse(root,root);
        }
        
    }
    void right_align(TreeNode * curr_node)
    {
        if(curr_node == NULL)
        {
            return;
        }
        if(curr_node->left != NULL)
        {
            curr_node->right = curr_node->left;
            curr_node->left = NULL;
        }
        right_align(curr_node->right);
    }
    void flatten(TreeNode* root) {
        
        traverse(root,root);
        right_align(root);
    }
};
