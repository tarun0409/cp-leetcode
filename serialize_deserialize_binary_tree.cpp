/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == NULL) return "#";
        string s = "";
       
        
        s+=serialize(root->left);
        s+=',';
        s+=serialize(root->right);
        s+=',';
        s+=to_string(root->val);
        return s;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty() || !data.compare("#")) return NULL;
        vector<string> dStr;
        string currString = ""; 
        for(int i=0; i<data.length(); i++)
        {
            if(data[i] == ',' && !currString.empty())
            {
                dStr.push_back(currString);
                currString = "";
            }
            else
            {
                currString += data[i];
            }
        }
        if(!currString.empty())
        {
            dStr.push_back(currString);
        }
        stack<pair<TreeNode *, int>> s;
        TreeNode * root = new TreeNode(stoi(dStr[dStr.size()-1]));
        s.push({root,2});
        for(int i=dStr.size()-2; i>=0; i--)
        {
            if(dStr[i][0]=='#')
            {
                pair<TreeNode *, int> p = s.top();
                s.pop();
                if(p.second == 2)
                {
                    p.first->right = NULL;
                }
                else if(p.second == 1)
                {
                    p.first->left = NULL;
                }
                p.second--;
                s.push(p);
            }
            else
            {
                TreeNode * currNode = new TreeNode(stoi(dStr[i]));
                s.push({currNode, 2});
            }
            TreeNode * currNode = NULL;
            while(!s.empty())
            {
                pair<TreeNode * , int> p = s.top();
                s.pop();
                if(currNode != NULL)
                {
                    if(p.second == 2)
                    {
                        p.first->right = currNode;
                    }
                    else if(p.second == 1)
                    {
                        p.first->left = currNode;
                    }
                    p.second--;
                }
                if(p.second > 0)
                {
                    s.push(p);
                    break;
                }
                currNode = p.first;
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
