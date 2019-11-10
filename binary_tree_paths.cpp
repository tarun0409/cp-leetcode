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
    vector<string> binaryTreePathsUtil(TreeNode * currNode)
    {
        if(currNode->left == NULL && currNode->right == NULL)
        {
            vector<string> ret;
            ret.push_back(to_string(currNode->val));
            return ret;
        }
        vector<string> ret;
        if(currNode->left != NULL)
        {
            vector<string> l = binaryTreePathsUtil(currNode->left);
            for(int i=0; i<l.size(); i++)
            {
                ret.push_back(to_string(currNode->val)+"->"+l[i]);
            }
        }
        if(currNode->right != NULL)
        {
            vector<string> r = binaryTreePathsUtil(currNode->right);
            for(int i=0; i<r.size(); i++)
            {
                ret.push_back(to_string(currNode->val)+"->"+r[i]);
            }
        }
        return ret;
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        if(root == NULL)
        {
            vector<string> temp;
            return temp;
        }
        return binaryTreePathsUtil(root);
        
    }
};
