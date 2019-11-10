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
    TreeNode * lca = NULL;
    int lowestCommonAncestorUtil(TreeNode * currNode, TreeNode * p, TreeNode * q)
    {
        if(currNode == NULL)
        {
            return 0;
        }
        bool currNodeTrue = (currNode == p || currNode == q);
        int l = lowestCommonAncestorUtil(currNode->left, p, q);
        if(l < 0)
        {
            return -1;
        }
        else if(l == 1 && currNodeTrue)
        {
            lca = currNode;
            return -1;
        }
        int r = lowestCommonAncestorUtil(currNode->right, p, q);
        if(r<0)
        {
            return -1;
        }
        if((r == 1 && currNodeTrue) || (l==1 && r==1))
        {
            lca = currNode;
            return -1;
        }
        return (l==1 || r==1 || currNodeTrue)?1:0;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL)
        {
            return NULL;
        }
        int found = lowestCommonAncestorUtil(root,p,q);
        if(found >= 0)
        {
            return NULL;
        }
        return lca;
    }
};
