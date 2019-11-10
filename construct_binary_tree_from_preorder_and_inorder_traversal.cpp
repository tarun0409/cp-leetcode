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
    int pre_index = 0;
    TreeNode* buildTreeUtil(vector<int>&preorder, vector<int>& inorder, int start_index, int end_index)
    {
        if(start_index > end_index)
        {
            return NULL;
        }
        TreeNode * new_node = new TreeNode(preorder[pre_index]);
        pre_index++;
        
        if(start_index == end_index)
        {
            return new_node;
        }
        
        int i=start_index;
        for( ; i<end_index; i++)
        {
            if(inorder[i]==new_node->val)
            {
                break;
            }
        }
        new_node->left = buildTreeUtil(preorder,inorder,start_index,i-1);
        new_node->right = buildTreeUtil(preorder,inorder,i+1,end_index);
        return new_node;
        
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTreeUtil(preorder,inorder,0,inorder.size()-1);        
    }
};
