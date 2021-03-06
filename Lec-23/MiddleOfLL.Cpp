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

Node* midOfLL(Node* head){
    if(head==NULL)
        return head;
    if(head->next==NULL)
        return head;

    Node* s=head;
    Node* f=head->next;

    //move slow pointer at 1x speed and fast at 2x;
    while(f!=NULL && f->next!=NULL){  //check if you can take 2 step or not
            s=s->next;
            f=f->next;
            f=f->next;

    }

    return s;

}


//checking whether there is cycle or not
bool checkCycle(Node* head){
    if(head==NULL)
        return false;
    Node* s=head;
    Node* f=head;
    while(f!=NULL && f->next!=NULL){

        s=s->next;
        f=f->next->next;
     if(f==s)
            return true;

    }
  return false;

}


//creating a cycle in non-cycled linked list
void createACycle(Node* head){
    //go to last node
    Node* curr=head;
    while(curr->next!=NULL)
        curr=curr->next;

    //after last node add head
    curr->next=head->next->next;

}

void detectAndRemoveCycle(Node* head){
    if(head==NULL)
        return;
    if(head->next==NULL)
        return;

    Node* s=head;
    Node* f=head;
    while(f!=NULL && f->next!=NULL){

        s=s->next;
        f=f->next->next;
     if(f==s)
        break;

    }

    //no cycle
    if(f==NULL || f->next==NULL)
        return;

 // cout << "Yes" ;
    //cycle case
    s=head;
    Node* prev = NULL; //this will keep track of prev of fast pointer

    while(f!=s){  //as long as they don't meet again
                   //they will meet at starting point of cycle
        //move both at same pace and you have to keep track of prev of fast pointer
        prev= f;
        f=f->next;
        s=s->next;

    }
  // cout << f->val<< endl;
    //prev is pointing to last node,just make it's next to be NULL
    prev->next=NULL;


}


//write delete at any postion
int main(){
 Node* head =NULL;  //this is going to store the address of first element of linked list
 insertAtStart(head,6);
 insertAtStart(head,5);
 insertAtStart(head,4);
 insertAtStart(head,3);
 insertAtStart(head,2);
 insertAtStart(head,1);

// Node* mid = midOfLL(head);

 // cout << mid->val<< endl;

 createACycle(head);

 //PrintLL(head);

 detectAndRemoveCycle(head);

 PrintLL(head);



/* if(checkCycle(head)){
    cout << "Yes" << endl;
 }
 else
    cout << "No" << endl; */







}
