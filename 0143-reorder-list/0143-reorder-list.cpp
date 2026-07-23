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
        if(head==NULL || head->next==NULL)
        {
            return head;
        }
        ListNode* newhead=reverse(head->next);
        ListNode* front=head->next;
        front->next=head;
        head->next=NULL;
        return newhead;
    }
    void reorderList(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* prev=head;
        if(head==NULL || head->next==NULL) return ;
        while(fast!=NULL && fast->next!=NULL)
        {
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* head2=prev->next;
        prev->next=NULL;
        head2= reverse(head2);
        ListNode* temp1=head;
        ListNode* temp2=head;
        ListNode* temp3=head2;
        ListNode* temp4=head2;
        while(temp1!=NULL)
        {
            temp2=temp1->next;
            temp1->next=temp3;
            temp4=temp3->next;
            temp3->next=temp2;
            temp1=temp2;
            temp3=temp4;
        }
        ListNode* temp=head;
        if(temp3!=NULL)
        {
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next=temp3;
        }
        
    }
};