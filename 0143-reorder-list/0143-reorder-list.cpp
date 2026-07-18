
class Solution {
public: 
  ListNode* reverse(ListNode* head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    ListNode* last = reverse(head->next);
    head->next->next = head;
    head->next = NULL;
    return last;
}

    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode*fast= head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* rev = reverse(slow);
        ListNode* curr = head;
        while(rev->next != NULL){
            ListNode* tempcurr =  curr->next;
            curr->next = rev;
            ListNode* temprev = rev->next;
            rev->next = tempcurr;
            curr = tempcurr;
            rev= temprev;
        }
    }
};