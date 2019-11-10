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
    int n = 0;
    int k_small = 0;
    void kthSmallestUtil(TreeNode * curr_node, int k)
    {
        if(curr_node == NULL)
        {
            return;
        }
        kthSmallestUtil(curr_node->left,k);
        n++;
        if(n==k)
        {
            k_small = curr_node->val;
        }
        kthSmallestUtil(curr_node->right,k);
    }
    int kthSmallest(TreeNode* root, int k) {
        kthSmallestUtil(root,k);
        return k_small;
    }
};
