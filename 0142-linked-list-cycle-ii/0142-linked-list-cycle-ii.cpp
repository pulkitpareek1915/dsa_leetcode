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
 ListNode *cheak(ListNode *head,ListNode *slow,ListNode *fast)
    {
        while(fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast)
            {
                return slow;
            }
        }
        return NULL;
    }
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow=head;
        ListNode *fast=head;
        if(head==NULL || head->next==NULL || cheak(head,slow,fast)==NULL)
        {
            return NULL;
        }
        fast=cheak(head,slow,fast);
        slow=head;
        
            while(slow!=fast)
            {
                slow=slow->next;
                fast=fast->next;
            }
        
        
            return slow;
    }
};