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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* slow=head;
        ListNode* fast=head;
        if(head==NULL || head->next==NULL)
        {
            return NULL;
        }
        for(int i=0;i<n;i++)
        {
            fast=fast->next;
        }
        if(fast==NULL)
        {
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return head;
        }
        while(fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next;
        }
        ListNode* curr=slow->next;
        ListNode* prev=slow;
        
        prev->next=curr->next;
        
        curr->next=NULL;
        delete curr;
        return head;
    }
};