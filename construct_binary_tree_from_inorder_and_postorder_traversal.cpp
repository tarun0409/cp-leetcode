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
    int post_index;
    TreeNode* buildTreeUtil(vector<int>& inorder, vector<int>& postorder, int start_index, int end_index)
    {
        if(start_index > end_index)
        {
            return NULL;
        }
        TreeNode * new_node = new TreeNode(postorder[post_index]);
        post_index--;
        if(start_index == end_index)
        {
            return new_node;
        }
        int i = 0;
        for( ; i<inorder.size(); i++)
        {
            if(inorder[i]==new_node->val)
            {
                break;
            }
        }
        new_node->right = buildTreeUtil(inorder,postorder,i+1,end_index);
        new_node->left = buildTreeUtil(inorder,postorder,start_index,i-1);
        
        return new_node;
        
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        post_index = inorder.size()-1;
        return buildTreeUtil(inorder,postorder,0,inorder.size()-1);
        
        
    }
};
