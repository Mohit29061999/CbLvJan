/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

ListNode* midOfLL(ListNode* head){
    if(head==NULL)
        return head;
    if(head->next==NULL)
        return head;

    ListNode* s=head;
    ListNode* f=head->next;

    //move slow pointer at 1x speed and fast at 2x;
    while(f!=NULL && f->next!=NULL){  //check if you can take 2 step or not
            s=s->next;
            f=f->next;
            f=f->next;

    }

    return s;

}

ListNode* reverseLL(ListNode* head){
    if(head==NULL)
        return NULL;
    ListNode* prev = NULL;
    ListNode* curr=head;
    while(curr!=NULL){
        //store next
        ListNode* n = curr->next;

        //reverse curr
        curr->next=prev;

        //move to next node
        prev = curr;
        curr=n;
    }

    return prev;
}
class Solution {
public:
    bool isPalindrome(ListNode* head) {
         //get the mid node
        ListNode* mid= midOfLL(head);

        //pass the starting point of second half to reverse ll code
        mid->next = reverseLL(mid->next);

        ListNode* c1=head;
        ListNode* c2=mid->next;

        while(c2!=NULL){
            if(c1->val !=c2->val)
                return false;
            c1=c1->next;
            c2=c2->next;
        }

        return true;


    }
};
