class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
        ListNode* ODD  = head;
        ListNode* EVEN = head->next;
        ListNode* evenStart = head->next;
        while(EVEN != NULL && EVEN->next != NULL) {
            ODD->next  = EVEN->next;
            EVEN->next = EVEN->next->next; 
            ODD  = ODD->next;
            EVEN = EVEN->next;
        }
        ODD->next = evenStart;
        return head;
        
    }
};