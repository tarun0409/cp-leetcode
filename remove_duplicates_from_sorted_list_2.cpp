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
        if(head == NULL || head->next==NULL) return head;
        ListNode * ptr1 = NULL;
        ListNode * ptr2 = head;
        int rValue;
        while(ptr2!=NULL)
        {
            if(ptr2->next!=NULL && ptr2->val==ptr2->next->val)
            {
                rValue = ptr2->val;
                while(ptr2!=NULL && ptr2->val==rValue) ptr2 = ptr2->next;
                if(ptr1!=NULL) ptr1->next = ptr2;
                else head = ptr2;
                
            }
            else
            {
                if(ptr1==NULL) head = ptr2;
                ptr1 = ptr2;
                ptr2 = ptr2->next;
            }
        }
        return head;
        
    }
};
