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
    void insert_node(ListNode ** head, ListNode ** curr_node, ListNode * new_node)
    {
        if (*head==NULL)
        {
            *head = new_node;
            *curr_node = new_node;
        }
        else
        {
            (*curr_node)->next = new_node;
            *curr_node = new_node;
        }
    }
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        ListNode * head1 = l1;
        ListNode * head2 = l2;
        ListNode * new_head = NULL;
        ListNode * curr_node = NULL;
        while(head1!=NULL && head2!=NULL)
        {
            if(head1->val <= head2->val)
            {
                ListNode * ins = head1;
                head1 = head1->next;
                ins->next = NULL;
                insert_node(&new_head, &curr_node, ins);
            }
            else
            {
                ListNode * ins = head2;
                head2 = head2->next;
                ins->next = NULL;
                insert_node(&new_head, &curr_node, ins);
            }
        }
        while(head1!=NULL)
        {
            ListNode * ins = head1;
            head1 = head1->next;
            ins->next = NULL;
            insert_node(&new_head, &curr_node, ins);
        }
        while(head2!=NULL)
        {
            ListNode * ins = head2;
            head2 = head2->next;
            ins->next = NULL;
            insert_node(&new_head, &curr_node, ins);
        }
        return new_head;
        
    }
};
