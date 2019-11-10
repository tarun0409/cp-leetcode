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
    int sum;
    void sumOfLeftLeavesUtil(TreeNode * currNode, bool left)
    {
        if(currNode == NULL) return;
        if(currNode->left == NULL && currNode->right == NULL && left)
        {
            sum+=currNode->val;
            return;
        }
        sumOfLeftLeavesUtil(currNode->left, true);
        sumOfLeftLeavesUtil(currNode->right, false);
        
    }
    int sumOfLeftLeaves(TreeNode* root) {
        if(root == NULL) return 0;
        sum = 0;
        sumOfLeftLeavesUtil(root,false);
        return sum;
    }
};
