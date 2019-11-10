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
    bool hasPathSum(TreeNode * curr_node, int curr_sum, int expected_sum)
    {
        int next_sum = curr_sum + curr_node->val;
        if(curr_node->left == NULL && curr_node->right == NULL)
        {
            if(next_sum == expected_sum)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        bool l = false;
        bool r = false;
        if(curr_node->left != NULL)
        {
            l = hasPathSum(curr_node->left,next_sum,expected_sum);
        }
        if(curr_node->right != NULL)
        {
            r = hasPathSum(curr_node->right,next_sum,expected_sum);
        }
        return l||r;
    }
    bool hasPathSum(TreeNode* root, int sum) {
        if(root == NULL && sum == 0)
        {
            return false;
        }
        else if(root == NULL)
        {
            return false;
        }
        return hasPathSum(root,0,sum);
    }
};
