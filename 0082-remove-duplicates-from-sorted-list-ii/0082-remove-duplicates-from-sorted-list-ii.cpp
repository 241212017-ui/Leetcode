class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {

        // Remove duplicate groups from the beginning
        while (head != NULL && head->next != NULL &&
               head->val == head->next->val) {

            int x = head->val;

            while (head != NULL && head->val == x)
                head = head->next;
        }

        if (head == NULL)
            return NULL;

        ListNode* prev = head;
        ListNode* curr = head->next;

        while (curr != NULL) {

            // Found a duplicate group
            if (curr->next != NULL && curr->val == curr->next->val) {

                int x = curr->val;

                while (curr != NULL && curr->val == x)
                    curr = curr->next;

                prev->next = curr;
            }
            else {
                prev = curr;
                curr = curr->next;
            }
        }

        return head;
    }
};