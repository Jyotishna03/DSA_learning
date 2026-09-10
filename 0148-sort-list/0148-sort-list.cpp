class Solution {
public:
    ListNode* sortList(ListNode* head) {

        // 0 or 1 node = already sorted
        if (head == NULL || head->next == NULL)
            return head;

        // Find middle
        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Divide into two lists
        ListNode* mid = slow->next;
        slow->next = NULL;

        // Sort both halves
        ListNode* left = sortList(head);
        ListNode* right = sortList(mid);

        // Merge
        return merge(left, right);
    }

    ListNode* merge(ListNode* left, ListNode* right) {

        ListNode dummy(0);
        ListNode* curr = &dummy;

        while (left != NULL && right != NULL) {

            if (left->val < right->val) {
                curr->next = left;
                left = left->next;
            }
            else {
                curr->next = right;
                right = right->next;
            }

            curr = curr->next;
        }

        if (left != NULL)
            curr->next = left;

        if (right != NULL)
            curr->next = right;

        return dummy.next;
    }
};