/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class BSTIterator {
public:
    TreeNode * root;
    vector<int> arr;
    int curr_index;
    
    BSTIterator(TreeNode* root) {
        curr_index = 0;
        inorder_fill(root);
    }
    
    void inorder_fill(TreeNode * curr_node)
    {
        if(curr_node == NULL)
        {
            return;
        }
        inorder_fill(curr_node->left);
        arr.push_back(curr_node->val);
        inorder_fill(curr_node->right);
    }
    
    /** @return the next smallest number */
    int next() {
        return arr[curr_index++];
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return curr_index < arr.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
