class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next || !head->next->next)
            return head;
        ListNode* start = head;
        ListNode* end   = head;
        int count = 1;
        while(end && end->next) {
            end = end->next;
            count++;
        }
        count /= 2;
        while(count--) {
            ListNode* startNext = start->next;
            start->next = start->next->next;
            end->next = startNext;
            start = start->next;
            end = end->next;
        }
        end->next = NULL;
        return head;
    }
};