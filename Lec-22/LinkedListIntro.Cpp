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

void insertAtStart(Node* &head,int v){
    //creating a new node which is to be added at front
  //  int* n =new int;
    Node *n =new Node(v);

    //check if it is first node
    if(head==NULL){
            //make this node as first node
        head =n;
        return;

    }

    n->next  =head;
    //make n as head or not?????
    head = n;
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

void insertAtAnyPos(Node* &head,int v,int pos){
    if(pos==0){
        insertAtStart(head,v);
        return;
    }
    if(pos>=LengthLL(head)-1){
        insertAtEnd(head,v);
        return;
    }
    Node* n=new Node(v);
    Node* curr=head;
    //move to that node after which this node is to added
    for(int i=1;i<=pos-1;i++){
        curr=curr->next;
    }

    n->next=curr->next;
    curr->next = n;
}
//print the elements of Linked list
void PrintLL(Node* head){
    while(head!=NULL){
        cout << head->val << " ";
        //go to next node
        head= head->next;
    }

}

void deleteFromStart(Node* &head){
    //whether LL is already empty
    if(head==NULL)
        return;

    Node* curr=head;
    head=head->next;
    //delete the object from heap too
    delete curr;
    curr=NULL;
}

void deleteFromEnd(Node* &head){
    //whether LL is already empty
    if(head==NULL)
        return;

    //if head is the last code
    if(head->next==NULL){
        //ll will become empty
        Node* curr=head;
        head=NULL;
        delete curr;
        return;
    }

    //one node before curr;
    Node* prev =NULL;
    Node* curr=head;
    while(curr->next!=NULL){
        prev =curr;

        //move curr one step ahead
        curr=curr->next;
    }


    prev->next=NULL;
    delete curr;



}

//searching a value in  a LL
Node* searchLL(Node* head,int key){
    while(head!=NULL){
        if(head->val==key)
            return head;
        //move forward
        head=head->next;
    }

    return NULL;
}

//recursive searchLL
Node* searchRecLL(Node* head,int key){
    //base case
    if(head==NULL)
        return NULL;

    //if head is equal to that value
    if(head->val ==key){
        return head;
    }

    //recursion will check the rest of the node
    return searchRecLL(head->next,key);
}


//write delete at any postion
int main(){
 Node* head =NULL;  //this is going to store the address of first element of linked list
 insertAtStart(head,10);
 insertAtStart(head,20);
 insertAtStart(head,30);
 insertAtStart(head,40);

 /*PrintLL(head);

 Node* head1=NULL;
 insertAtEnd(head1,10);
  insertAtEnd(head1,20);
   insertAtEnd(head1,30);
    insertAtEnd(head1,40);

    PrintLL(head1);
    cout << endl;
    insertAtAnyPos(head1,15,1);

    PrintLL(head1);  */

    //deleteFromStart(head);
    //deleteFromStart(head);

    //deleteFromEnd(head);
    //deleteFromEnd(head);

    Node* n=searchRecLL(head,10);
    if(n!=NULL)
    cout << n->val << endl;
    else
        cout << "doesn't exist" << endl;

    //PrintLL(head);



}
