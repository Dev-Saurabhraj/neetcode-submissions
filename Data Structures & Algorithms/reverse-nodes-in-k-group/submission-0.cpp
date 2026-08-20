class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(0);
        dummy.next = head;

        ListNode* groupPrev = &dummy;

        while (true) {

            // Find kth node
            ListNode* kth = groupPrev;

            for (int i = 0; i < k; i++) {
                kth = kth->next;

                if (kth == NULL)
                    return dummy.next;
            }

            // Save the node after the group
            ListNode* groupNext = kth->next;

            // Reverse current group
            ListNode* prev = groupNext;
            ListNode* curr = groupPrev->next;

            while (curr != groupNext) {
                ListNode* temp = curr->next;

                curr->next = prev;
                prev = curr;
                curr = temp;
            }

            // Connect previous group to reversed group
            ListNode* oldGroupStart = groupPrev->next;
            groupPrev->next = kth;

            // Move groupPrev to the end of reversed group
            groupPrev = oldGroupStart;
        }

        return dummy.next;
    }
};