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
    
    vector<int> nums;
    void sumNumbersUtil(TreeNode * curr_node, int num)
    {
        num = num*10 + curr_node->val;
        if(curr_node->left == NULL && curr_node->right == NULL)
        {
            nums.push_back(num);
        }
        else
        {
            if(curr_node->left != NULL)
            {
                sumNumbersUtil(curr_node->left, num);
            }
            if(curr_node->right != NULL)
            {
                sumNumbersUtil(curr_node->right, num);
            }
        }
    }
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        if(root != NULL)
        {
            sumNumbersUtil(root,0);
            for(int i=0; i<nums.size(); i++)
            {
                sum += nums[i];
            }
        }
        return sum;
        
    }
};
