class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        int len = 0;
        ListNode *temp = head;

        while (temp) {
            len++;
            temp = temp->next;
        }

        // Delete head
        if (len == n) {
            temp = head;
            head = head->next;
            delete temp;
            return head;
        }

        ListNode *curr = head;
        ListNode *prev = NULL;
        int cnt = 0;

        while (cnt < len - n) {
            prev = curr;
            curr = curr->next;
            cnt++;
        }

        prev->next = curr->next;
        delete curr;

        return head;
    }
};