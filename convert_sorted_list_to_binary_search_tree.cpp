/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBSTUtil(ListNode * start, ListNode * end)
    {
        if(start==NULL && end==NULL)
        {
            return NULL;
        }
        if(start!=NULL && end == NULL)
        {
            return new TreeNode(start->val);
        }
        if(start==NULL && end!=NULL)
        {
            return NULL;
        }
        if(start==end)
        {
            return new TreeNode(start->val);
        }
        ListNode * fastPtr = start;
        ListNode * slowPtr = start;
        ListNode * endPtr = start;
        ListNode * startPtr = start;
        bool firstMove = true;
        while(fastPtr != end->next)
        {
            fastPtr = fastPtr->next;
            if(fastPtr!=end->next)
            {
                fastPtr = fastPtr->next;
                slowPtr = slowPtr->next;
                if(slowPtr == end)
                {
                    startPtr = NULL;
                }
                else
                {
                    startPtr = slowPtr->next;   
                }
                if(!firstMove)
                {
                    endPtr = endPtr->next;
                }
                else
                {
                    firstMove = false;
                }
            }
        }
        TreeNode * left = sortedListToBSTUtil(start,endPtr);
        TreeNode * right = sortedListToBSTUtil(startPtr,end);
        TreeNode * currNode = new TreeNode(slowPtr->val);
        currNode->left = left;
        currNode->right = right;
        return currNode;
        
    }
    TreeNode* sortedListToBST(ListNode* head) {
        if(head == NULL)
        {
            return NULL;
        }
        if(head->next == NULL)
        {
            return new TreeNode(head->val);
        }
        ListNode * endPtr = head;
        while(endPtr->next != NULL)
        {
            endPtr = endPtr->next;
        }
        return sortedListToBSTUtil(head, endPtr);
    }
};
