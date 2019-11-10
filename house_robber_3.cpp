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
    unordered_map<int,int> levelBounty;
    int maxLevel;
    pair<int,int> robUtil(TreeNode* root)
    {
	    if(!root) return {0, 0};

	    pair<int, int> right = robUtil(root->right);
	    pair<int, int> left = robUtil(root->left);

	    return {max(root->val + right.second + left.second, right.first + left.first), right.first + left.first};
    }
    int rob(TreeNode* root) {
        return robUtil(root).first;
    }
};
