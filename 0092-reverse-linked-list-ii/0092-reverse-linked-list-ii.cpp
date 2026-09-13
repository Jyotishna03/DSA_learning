class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {

        if (head == NULL) {
            return NULL;
        }

        if (left == right) {
            return head;
        }

        ListNode* temp = head;
        ListNode* before = NULL;
        int pos = 1;

        // Reach the left position
        while (pos < left) {
            before = temp;
            temp = temp->next;
            pos++;
        }

        // temp is now at left
        ListNode* first = temp;
        ListNode* prev = NULL;
        ListNode* curr = temp;

        int times = right - left + 1;

        // Reverse the required part
        while (times--) {
            ListNode* nex = curr->next;

            curr->next = prev;

            prev = curr;
            curr = nex;
        }

        // Connect the reversed part
        first->next = curr;

        if (before != NULL) {
            before->next = prev;
            return head;
        }

        // If left == 1
        return prev;
    }
};