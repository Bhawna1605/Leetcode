class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* a=headA;
        ListNode* b=headB;
        while(a!=b){
            a=(!a)?headA:a->next;
            b=(!b)?headB:b->next;
        }
        return a;
    }
};