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
    int countSum(TreeNode * currNode, int sum)
    {
        int count=0;
		if(currNode == NULL) return 0;
		if(currNode->val==sum) count+=1;
		count+=countSum(currNode->left,sum-currNode->val);
		count+=countSum(currNode->right,sum-currNode->val);
		return count;
    }
    int pathSum(TreeNode* root, int sum) {
        if(root == NULL) return 0;
		return countSum(root,sum)+pathSum(root->left,sum)+pathSum(root->right,sum);
    }
};
