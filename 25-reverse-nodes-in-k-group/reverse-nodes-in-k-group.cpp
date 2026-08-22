class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0);
        dummy -> next = head;
        ListNode* prevGroup = dummy;
        while(true){
            ListNode* kth = prevGroup;
            for(int i = 0; i < k; i++){
                kth = kth -> next;

                if(kth == nullptr){
                    return dummy-> next;
                }
            }
            ListNode* groupNext = kth -> next;
            ListNode* prev = groupNext;
            ListNode* curr = prevGroup -> next;

            while (curr != groupNext) {

                // 13
                ListNode* next = curr->next;

                // 14
                curr->next = prev;

                // 15
                prev = curr;

                // 16
                curr = next;
            }

            // 17
            ListNode* oldStart = prevGroup->next;

            // 18
            prevGroup->next = kth;

            // 19
            prevGroup = oldStart;

        }
            
    }
};
