class Solution {
public:
    ListNode* partition(ListNode* head, int x) {

        ListNode smallDummy(0);
        ListNode largeDummy(0);

        ListNode* small = &smallDummy;
        ListNode* large = &largeDummy;

        while (head != NULL) {

            if (head->val < x) {
                small->next = head;
                small = small->next;
            }
            else {
                large->next = head;
                large = large->next;
            }

            head = head->next;
        }

        // End the large list
        large->next = NULL;

        // Connect small list to large list
        small->next = largeDummy.next;

        return smallDummy.next;
    }
};