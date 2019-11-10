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
    bool check_bst(TreeNode * curr_node, long smallest, long largest)
    {
        if(curr_node == NULL)
        {
            return true;
        }
        if((long)curr_node->val <= smallest || (long)curr_node->val >= largest)
        {
            return false;
        }
        return check_bst(curr_node->left,smallest,(long)curr_node->val) && check_bst(curr_node->right, (long)curr_node->val, largest);
        
    }
    bool isValidBST(TreeNode* root) {
        if(root == NULL)
        {
            return true;
        }
        //cout<<INT_MIN<<" "<<INT_MAX<<endl;
        return check_bst(root->left, ((long)(INT_MIN)-1), root->val) && check_bst(root->right, root->val, ((long)(INT_MAX))+1);
        
    }
};
