#include <iostream>
using namespace std;

class Node{
public:
    int val;
    Node *next;  //next is pointing to next node(next val and next to next address) and not integer alone

    Node(int v){
        val =v;
        //not sure about next node address currently
        next =NULL;
    }
};

int LengthLL(Node* head){
    int ans =0;
    while(head!=NULL){
        ans++;
        //go to next node
        head=head->next;
    }
    return ans;
}



void insertAtEnd(Node* &head,int v){
     //creating a new node which is to be added at front
  //  int* n =new int;
    Node *n =new Node(v);

     //check if it is first node
    if(head==NULL){
            //make this node as first node
        head =n;
        return;

    }

    Node* curr=head;
    //if next of a node is NULL then it is the last node
    while(curr->next!=NULL){
            //current is pointing to same address as current->next
        curr =curr->next;
    }

     //add the link between new node and last node
    curr->next=n;

}


//print the elements of Linked list
void PrintLL(Node* head){
    while(head!=NULL){
        cout << head->val << " ";
        //go to next node
        head= head->next;
    }

}





void bubbleSort(Node* &head){
    int n=LengthLL(head);
    for(int i=0;i<n-1;i++){
        Node* c=head;  //a[0]
        Node* prev = NULL;

        while(c!=NULL && c->next!=NULL){
            Node* n =c->next;
            if(c->val<=n->val){
                    //already correct order
                prev = c;
                c=n;
            }
            else{
                //change link
                if(prev ==NULL){
                    //if it is first node then head should also change
                    c->next= n->next;
                    n->next  = c;
                    head=n;
                    prev = n;
                }
                else{
                    //it is not head
                    c->next = n->next;
                    n->next  = c;
                    prev->next =n;
                    prev= n;
                }
            }
        }
    }
}














//write delete at any postion
int main(){
 Node* head =NULL;  //this is going to store the address of first element of linked list


   insertAtEnd(head,1);
 insertAtEnd(head,5);
 insertAtEnd(head,3);
 insertAtEnd(head,2);
// insertAtEnd(head,2);
// insertAtEnd(head,1);


 //head= reverseKGroup(head,k);
  bubbleSort(head);
  PrintLL(head);








}
