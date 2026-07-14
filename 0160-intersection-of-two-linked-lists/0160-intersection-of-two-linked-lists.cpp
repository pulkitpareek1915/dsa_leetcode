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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *temp1=headA;
        ListNode *temp2=headB;
        int len1=0;
        int len2=0;
        while(temp1!=NULL)
        {
            len1++;
            temp1=temp1->next;
        }
        while(temp2!=NULL)
        {
            len2++;
            temp2=temp2->next;
        }
        temp1=headA;
        temp2=headB;
        int cnt=abs(len1-len2);
        if(len1>len2)
        {
            int a=0;
            while(temp1!=NULL && a!=cnt)
            {
                a++;
                temp1=temp1->next;
            }
        }
        else{
            int a=0;
            while(a!=cnt)
            {
                a++;
                temp2=temp2->next;
            }
        }
        while(temp1!=NULL)
        {
            if(temp1==temp2)
            {
                return temp1;
            }
             temp1=temp1->next;
              temp2=temp2->next;
        }
        return NULL;
    }
};