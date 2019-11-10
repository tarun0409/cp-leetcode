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
    vector<TreeNode *> generateTreesUtil(int start, int end)
    {
        vector<TreeNode *> list;
        if(start > end)
        {
            list.push_back(NULL);
            return list;
        }
        for(int i=start; i<=end; i++)
        {
            vector<TreeNode *> leftSubTree = generateTreesUtil(start, i-1);
            vector<TreeNode *> rightSubTree = generateTreesUtil(i+1, end);
            for(int j=0; j<leftSubTree.size(); j++)
            {
                TreeNode * leftSubTreeNode = leftSubTree[j];
                for(int k=0; k<rightSubTree.size(); k++)
                {
                    TreeNode * rightSubTreeNode = rightSubTree[k];
                    TreeNode * new_node = new TreeNode(i);
                    new_node->left = leftSubTreeNode;
                    new_node->right = rightSubTreeNode;
                    list.push_back(new_node);
                }
            }
        }
        return list;
    }
    vector<TreeNode*> generateTrees(int n) {
        if(n==0)
        {
            vector<TreeNode *> dummy;
            return dummy;
        }
        
        return generateTreesUtil(1, n);
        
    }
};
