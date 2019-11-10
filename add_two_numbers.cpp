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
    ListNode * createNode(int value)
    {
        ListNode * new_node = new ListNode(value);
        new_node->next = NULL;
        return new_node;
    }
    void addNode(ListNode ** head, ListNode ** tail, ListNode * new_node)
    {
        if(*head == NULL)
        {
            *head = new_node;
            *tail = new_node;
        }
        else
        {
            (*tail)->next = new_node;
            *tail = new_node;
        }
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        int n1=0,n2=0;
        ListNode * sumHead = NULL;
        ListNode * sumTail = NULL;
        ListNode * temp1 = l1;
        while(temp1!=NULL)
        {
            n1++;
            temp1 = temp1->next;
        }
        temp1 = l2;
        while(temp1!=NULL)
        {
            n2++;
            temp1 = temp1->next;
        }
        temp1 = l1;
        ListNode * temp2 = l2;
        int carry = 0;
        while(temp1!=NULL && temp2!=NULL)
        {
            int sum = temp1->val + temp2->val + carry;
            int value = sum%10;
            carry = sum/10;
            ListNode * new_node = createNode(value);
            addNode(&sumHead,&sumTail,new_node);
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        while(temp1!=NULL)
        {
            int sum = temp1->val + carry;
            int value = sum%10;
            carry = sum/10;
            ListNode * new_node = createNode(value);
            addNode(&sumHead,&sumTail,new_node);
            temp1 = temp1->next;
        }
        while(temp2!=NULL)
        {
            int sum = temp2->val + carry;
            int value = sum%10;
            carry = sum/10;
            ListNode * new_node = createNode(value);
            addNode(&sumHead,&sumTail,new_node);
            temp2 = temp2->next;
        }
        if(carry!=0)
        {
            ListNode * new_node = createNode(carry);
            addNode(&sumHead,&sumTail,new_node);
        }
        return sumHead;
        
    }
};
