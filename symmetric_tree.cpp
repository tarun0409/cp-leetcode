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
    bool isSymmetricUtil(TreeNode * curr_node1, TreeNode * curr_node2)
    {
        if(curr_node1 == NULL && curr_node2 == NULL)
        {
            return true;
        }
        if(curr_node1 != NULL && curr_node2 != NULL && curr_node1->val == curr_node2->val)
        {
            return isSymmetricUtil(curr_node1->left,curr_node2->right) && isSymmetricUtil(curr_node1->right, curr_node2->left);
        }
        return false;
    }
    bool isSymmetric(TreeNode* root) {
        return isSymmetricUtil(root,root);
    }
};
