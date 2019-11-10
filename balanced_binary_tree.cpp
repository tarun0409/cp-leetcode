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
    bool balanced = true;
    int isBalancedUtil(TreeNode * curr_node)
    {
        if(curr_node == NULL)
        {
            return 0;
        }
        int lh = isBalancedUtil(curr_node->left);
        int rh = isBalancedUtil(curr_node->right);
        int diff = (lh > rh)?(lh-rh):(rh-lh);
        if(diff > 1)
        {
            balanced = false;
        }
        return 1+(lh>rh?lh:rh);
    }
    bool isBalanced(TreeNode* root) {
        int h = isBalancedUtil(root);
        return balanced;
    }
};
