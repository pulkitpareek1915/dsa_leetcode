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
    int numComponents(ListNode* head, vector<int>& nums) {
        unordered_map<int,int> map;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            map[nums[i]]++;
        }
        ListNode* temp=head;
        int ans=0;
        int cnt=0;
        while(temp!=NULL)
        {
            if(map.find(temp->val)!=map.end())
            {
                cnt++;
            }
            else{
                if(cnt)
                {
                    ans++;
                }
                cnt=0;
            }
            temp=temp->next;
        }
        if(cnt) ans++;
        return ans;
    }
};