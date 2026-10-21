class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return NULL;
        }
        ListNode* PrevSlow=NULL;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL && fast->next!=NULL){
            PrevSlow=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        PrevSlow->next=slow->next;
        delete(slow);
        return head;
    }
};