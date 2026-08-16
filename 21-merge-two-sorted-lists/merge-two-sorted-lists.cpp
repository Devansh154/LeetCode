class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        if(list1 == nullptr)
            return list2;

        if(list2 == nullptr)
            return list1;

        ListNode* p = list1;
        ListNode* q = list2;

        ListNode* head = nullptr;
        ListNode* tail = nullptr;

        while(p != nullptr && q != nullptr) {

            if(p->val <= q->val) {

                if(head == nullptr) {
                    head = p;
                    tail = p;
                }
                else {
                    tail->next = p;
                    tail = p;
                }

                p = p->next;
            }
            else {

                if(head == nullptr) {
                    head = q;
                    tail = q;
                }
                else {
                    tail->next = q;
                    tail = q;
                }

                q = q->next;
            }
        }

        if(p != nullptr) {
            tail->next = p;
        }
        else {
            tail->next = q;
        }

        return head;
    }
};