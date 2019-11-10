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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL) return NULL;
        if(head->next == NULL) return head;
        if(head->next->next == NULL)
        {
            ListNode * temp = head;
            head = head->next;
            head->next = temp;
            temp->next = NULL;
            return head;
        }
        ListNode * front = head->next;
        ListNode * rear = head;
        ListNode * nextFront = head->next->next->next;
        ListNode * nextRear = head->next->next;
        ListNode * prevElement = NULL;
        bool headFixed = false;
        while(front != NULL)
        {
            if(!headFixed)
            {
                head = front;
                headFixed = true;
            }
            front->next = rear;
            rear->next = nextRear;
            if(prevElement != NULL)
            {
                prevElement->next = front;
            }
            prevElement = rear;
            front = nextFront;
            rear = nextRear;
            if(nextFront!=NULL)
            {
                nextFront = nextFront->next;
                if(nextFront!=NULL)
                {
                    nextFront = nextFront->next;
                }
            }
            if(nextRear!=NULL)
            {
                nextRear = nextRear->next;
                if(nextRear!=NULL)
                {
                    nextRear = nextRear->next;
                }
            }
        }
        return head;
    }
};
