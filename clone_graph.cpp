/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
public:
    unordered_map<int, Node *> valToNode;
    void cloneGraphUtil(Node * currNode, Node * newNode)
    {
        for(int i=0; i<currNode->neighbors.size(); i++)
        {
            Node * n = currNode->neighbors[i];
            if(valToNode.find(n->val) != valToNode.end())
            {
                newNode->neighbors.push_back(valToNode[n->val]);
            }
            else
            {
                Node * nextNewNode = new Node();
                nextNewNode->val = n->val;
                valToNode[n->val] = nextNewNode;
                newNode->neighbors.push_back(nextNewNode);
                cloneGraphUtil(n,nextNewNode);
            }
        }
    }
    Node* cloneGraph(Node* node) {
        if(node == NULL) return NULL;
        Node * newNode = new Node();
        newNode->val = node->val;
        valToNode[node->val] = newNode;
        cloneGraphUtil(node, newNode);
        return newNode;
    }
};
