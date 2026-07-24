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
    ListNode* removeZeroSumSublists(ListNode* head) {
       ListNode* front=new ListNode(0,head);
       ListNode* curr=front;
       int ps=0;
       unordered_map<int,ListNode*> psmap;
       psmap[0]=front;
       while(curr!=NULL)
       {
            ps+=curr->val;
            psmap[ps]=curr;
            curr=curr->next;
       } 
       ps=0;
       curr=front;
       while(curr!=NULL)
       {
            ps+=curr->val;
            curr->next=psmap[ps]->next;
            curr=curr->next;
       }
       return front->next;
    }
};