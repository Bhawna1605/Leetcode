class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        auto a=headA,b=headB;
        while(a!=b){
            a=(!a)?headA:a->next;
            b=(!b)?headB:b->next;
        }
        return a;
    }
};