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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> values;
        ListNode* temp=head;
        while(temp!=NULL)
        {
            values.push_back(temp->val);
            temp=temp->next;
        }
        stack<int> stk;
        int n=values.size();
        vector<int> greater(n,0);
        for(int i=0;i<n;i++)
        {
            while(!stk.empty() && values[i]>values[stk.top()])
            {
                int index=stk.top();
                stk.pop();
                greater[index]=values[i];
            }
            stk.push(i);
        }
        return greater;
    }
};