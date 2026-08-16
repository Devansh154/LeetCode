class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {

        ListNode* curr = head;

        while(curr != nullptr && curr->next != nullptr) {

            if(curr->next->val == curr->val) {

                ListNode* temp = curr->next;

                curr->next = curr->next->next;

                delete temp;
            }
            else {
                curr = curr->next;
            }
        }

        return head;
    }
};