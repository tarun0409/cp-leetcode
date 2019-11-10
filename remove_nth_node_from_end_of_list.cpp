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
    int removeNthFromEndUtil(ListNode * currNode, int n)
    {
        if(currNode == NULL)
        {
            return 1;
        }
        int ret_val = removeNthFromEndUtil(currNode->next, n);
        if(ret_val == -1) return -1;
        if(ret_val == (n+1))
        {
            currNode->next = currNode->next->next;
            return -1;
        }
        return (ret_val+1);
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL) return NULL;
        int ret_val = removeNthFromEndUtil(head, n);
        if(ret_val != -1)
        {
            head = head->next;
        }
        return head;
        
    }
};
