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
    int maxDepthUtil(TreeNode * curr_node)
    {
        if(curr_node == NULL)
        {
            return 0;
        }
        int h1 = maxDepthUtil(curr_node->left);
        int h2 = maxDepthUtil(curr_node->right);
        return 1 + (h1>h2?h1:h2);
    }
    int maxDepth(TreeNode* root) {
        return maxDepthUtil(root);
        
    }
};
