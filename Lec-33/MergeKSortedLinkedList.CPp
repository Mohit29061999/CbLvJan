//problem link: https://leetcode.com/problems/merge-k-sorted-lists/
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

///create a min heap
class customClass{
    public:
    bool operator()(ListNode* l1,ListNode* l2){
        ///return true when i wan't to swap them
        return l1->val>l2->val;

    }

};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
      priority_queue<ListNode*,vector<ListNode*>,customClass>pq;

    int n=lists.size();

    ///insert the first node in priority_queue for all the linked list
    for(int i=0;i<n;i++){
         ListNode* curr = lists[i];
        if(curr!=NULL){ ///insert the first node only when it exists
                        ///so insert the node only when it is not NULL
            pq.push(curr);
        }
    }

    ///to keep track of head and tail of final linked list
    ListNode* head=NULL;
    ListNode* tail = NULL;

    while(!pq.empty()){
        ListNode* curr = pq.top();
        pq.pop();

        ///insert the next node of this linked list in the priority queue
        if(curr->next!=NULL){
            pq.push(curr->next);
        }
        ///if it is first node or not
        if(head==NULL){
            head=tail =curr;
            tail->next = NULL;

        }
        else{
            ///add this node after tail and make this as tail
            tail->next = curr;
            tail = curr;
            tail->next =NULL;

        }


    }
        return head;

    }
};
