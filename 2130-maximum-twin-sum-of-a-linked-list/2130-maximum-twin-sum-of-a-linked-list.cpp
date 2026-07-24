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
    ListNode*reverse(ListNode*head){
        ListNode*temp = head;
        ListNode*prev = NULL;
        while(temp!=NULL){
            ListNode*front = temp->next;
            temp ->next = prev;
            
            prev = temp;
            temp = front;


        }
        return prev;
    }
    int pairSum(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* prev=NULL;
        if(head->next->next==NULL) return head->val+head->next->val;
        while(fast!=NULL && fast->next!=NULL)
        {
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* head2=slow;
        prev->next=NULL;
        head2=reverse(head2);
        ListNode* temp1=head;
        ListNode* temp2=head2;
        int maxi=INT_MIN;
        int sum=0;
        while(temp1!=NULL && temp2!=NULL)
        {
            sum=temp1->val+temp2->val;
            cout<<sum <<" ";
            maxi=max(sum,maxi);
            temp1=temp1->next;
            temp2=temp2->next;
        }
        return maxi;
    }
};