/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode * kNode;
    ListNode * km1Node;
    ListNode * lastNode;
    int setPtrs(ListNode * currNode, int k)
    {
        if(currNode == NULL)
        {
            return 1;
        }
        int n = setPtrs(currNode->next,k);
        if(n==1)
        {
            lastNode = currNode;
        }
        if(n==k)
        {
            kNode = currNode;
        }
        if(n==(k+1))
        {
            km1Node = currNode;
        }
        return (n+1);
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL || k==0) return head;
        int n = setPtrs(head,k);
        n--;
        if(k>=n)
        {
            k=k%n;
            if(k==0) return head;
            n = setPtrs(head,k);
        }
        lastNode->next = head;
        head = kNode;
        km1Node->next = NULL;
        return head;
    }
};
