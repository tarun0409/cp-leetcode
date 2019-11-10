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
    int minDepthUtil(TreeNode * curr_node)
    {
        if(curr_node == NULL)
        {
            return 0;
        }
        int lh = minDepthUtil(curr_node->left);
        int rh = minDepthUtil(curr_node->right);
        if(lh == 0 && rh == 0)
        {
            return 1;
        }
        else if(lh == 0 && rh != 0)
        {
            return 1+rh;
        }
        else if(lh!=0 && rh==0)
        {
            return 1+lh;
        }
        return 1+((lh < rh)?lh:rh);
    }
    int minDepth(TreeNode* root) {
        return minDepthUtil(root);
    }
};
