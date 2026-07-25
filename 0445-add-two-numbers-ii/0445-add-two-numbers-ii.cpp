/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverse(ListNode* head)
    {
        ListNode* forward=head;
        ListNode* curr=head;
        ListNode* prev=NULL;
        while(curr!=NULL)
        {
            forward=forward->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
        }
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* r1=reverse(l1);
        ListNode* r2=reverse(l2);
        int sum=0;
        int carray=0;
        ListNode* dummy=new ListNode(-1);
        ListNode* curr=dummy;
        while(r1 || r2)
        {
            sum+=carray;
            if(r1)
            {
                sum+=r1->val;
            }
            if(r2)
            {
                sum+=r2->val;
            }
            ListNode* newnode=new ListNode(sum%10);
            carray=sum/10;
            curr->next=newnode;
            curr=curr->next;
            sum=0;
            if(r1)
            {
               r1=r1->next;
            }
            if(r2)
            {
                r2=r2->next;
            }
        }
        if(carray)
        {
            curr->next = new ListNode(carray);
        }
        return reverse(dummy->next);
    }
};