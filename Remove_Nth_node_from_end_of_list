class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* curr=head;
        int len=0;
        while(curr){
            curr=curr->next;
            len++;
        }
        int toFind= len-n;
        ListNode * prev=nullptr;
        ListNode * rem=head;
        int i=0;
        while(rem && i<toFind){
            prev=rem;
            rem=rem->next;
            i++;
        }
        if(prev!=nullptr){
        prev->next=rem->next;
        }
        else{
            head=head->next;
        }
        return head;
    }
};
