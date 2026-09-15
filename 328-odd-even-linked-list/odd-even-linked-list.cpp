class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head -> next == NULL){
            return head;
        }      
        ListNode* odd = head;
        ListNode* even = head -> next;
        ListNode* newhead = even;
        while(even != NULL && even -> next != NULL){
            odd -> next = even -> next;
            odd = odd -> next;
            even -> next = even -> next -> next;
            even = odd -> next;
        } 
        odd -> next = newhead;
        return head;
    }
};