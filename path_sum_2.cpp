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
    vector<vector<int>> pathSumUtil(TreeNode * curr_node, int curr_sum, int expected_sum)
    {
        vector<vector<int>> res;
        if(curr_node == NULL)
        {
            return res;
        }
        int next_sum = curr_sum + curr_node->val;
        if(curr_node->left == NULL && curr_node->right == NULL)
        {
            if(next_sum == expected_sum)
            {
                vector<int> nv;
                nv.push_back(curr_node->val);
                res.push_back(nv);
            }
            return res;
        }
        vector<vector<int>> left_vec = pathSumUtil(curr_node->left,next_sum,expected_sum);
        vector<vector<int>> right_vec = pathSumUtil(curr_node->right,next_sum,expected_sum);
        for(int i=0; i<left_vec.size(); i++)
        {
            vector<int> v = left_vec[i];
            v.insert(v.begin(),curr_node->val);
            res.push_back(v);
        }
        for(int i=0; i<right_vec.size(); i++)
        {
            vector<int> v = right_vec[i];
            v.insert(v.begin(),curr_node->val);
            res.push_back(v);
        }
        return res;
        
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        
        if(root == NULL)
        {
            vector<vector<int>> res;
            return res;
        }
        return pathSumUtil(root,0,sum);
        
    }
};
