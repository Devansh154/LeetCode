class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {

        if(head == nullptr || head->next == nullptr || k == 0){
            return head;
        }

        ListNode* curr = head;
        int len = 1;

        while(curr->next != nullptr){
            curr = curr->next;
            len++;
        }

        k = k % len;

        if(k == 0){
            return head;
        }

        // Make the list circular
        curr->next = head;

        curr = head;

        // Find the new tail
        for(int i = 0; i < len - k - 1; i++){
            curr = curr->next;
        }

        // New head
        head = curr->next;

        // Break the circle
        curr->next = nullptr;

        return head;
    }
};