/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/
class Solution {
public:
    Node* connect(Node* root) {
        
        if(root == NULL)
        {
            return NULL;
        }
        queue<Node *> q;
        queue<int> nums;
        q.push(root);
        nums.push(1);
        while(!q.empty())
        {
            int n = nums.front();
            nums.pop();
            int p = 0;
            Node * prev_node = NULL;
            for(int i=0; i<n; i++)
            {
                Node * node = q.front();
                q.pop();
                if(node->left != NULL)
                {
                    q.push(node->left);
                    p++;
                    
                }
                if(node->right != NULL)
                {
                    q.push(node->right);
                    p++;
                }
                if(i != 0)
                {
                    prev_node->next = node;
                }
                prev_node = node; 
            }
            if(prev_node != NULL)
            {
                prev_node->next = NULL;
            }
            nums.push(p);
        }
        return root;
        
    }
};
