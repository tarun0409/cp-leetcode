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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode * front = head->next;
        ListNode * back = head;
        while(front!=NULL)
        {
            if(front->val != back->val)
            {
                back->next = front;
                back = front;
            }
            front = front->next;
        }
        back->next = front;
        return head;
        
    }
};
