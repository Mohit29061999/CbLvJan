//problem link: https://leetcode.com/problems/odd-even-linked-list/

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
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
         if(head==NULL || head->next ==NULL)
             return head;
         ListNode* oddEnd = head;
        ListNode* evenHead = head->next;  ///first node of even linked list
        ListNode* evenEnd = head->next;

        int c=1;
        ListNode* curr=head->next->next;
        while(curr!=NULL){
            //decide whether this to be added to odd or even ll
            if(c%2==1){
                //this should come to odd
                oddEnd->next = curr;
                oddEnd = curr;
                curr=curr->next;
            }
            else{
                  //this should come to even
                evenEnd->next = curr;
                evenEnd = curr;
                curr=curr->next;
            }
           c++;
        }

        oddEnd->next = evenHead;
        evenEnd->next =NULL;
      //  cout << evenHead->val <<" " << evenEnd->val << endl;
        return head;
    }
};
