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



//print the elements of Linked list
void PrintLL(Node* head){
    while(head!=NULL){
        cout << head->val << " ";
        //go to next node
        head= head->next;
    }

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



//merge two sorted linked list
Node* merge(Node* h1,Node* h2){
    //base case: if one of ll is empty
    if(h1==NULL)
        return h2;
    if(h2==NULL)
        return h1;
    Node* temp ;
    if(h1->val<h2->val){
        temp = h1;
        //recursion will merge the remaining ll
        Node* restHead = merge(h1->next,h2);
        temp->next=restHead;
    }
    else{
         temp = h2;
        //recursion will merge the remaining ll
        Node* restHead = merge(h1,h2->next);
        temp->next=restHead;
    }
    return temp;  //return new head which is temp
}


Node* mergeSort(Node* head){
    //base case:if length is 1, do nothing already sorted
    if(head==NULL || head->next==NULL)
        return head;

    //divide the linked list in two
    Node* mid = midOfLL(head);  //mid is pointing to middle of liked list
    Node* secondHead = mid->next;
    mid->next=NULL;  //to break a ll into two ll list

    //sort both the half
    head=mergeSort(head);  //sorting the left half
    secondHead = mergeSort(secondHead);  //sorting the right half

    //merge both the sorted half
    Node* finalHead= merge(head,secondHead);
    return finalHead;

}

Node* reverseLL(Node* head){
    if(head==NULL)
        return NULL;
    Node* prev = NULL;
    Node* curr=head;
    while(curr!=NULL){
        //store next
        Node* n = curr->next;

        //reverse curr
        curr->next=prev;

        //move to next node
        prev = curr;
        curr=n;
    }

    return prev;
}

Node* reverseRec(Node* curr,Node* &head){ //head will store the head of reversed ll
    if(curr==NULL)
        return NULL;


    //code for last node
    if(curr->next==NULL){
       head=curr;
        return curr;
       }
    Node* temp =curr;
    Node* n =curr->next;
    curr->next=NULL;
    Node* restLL =reverseRec(n,head);
    restLL->next = temp;
    return temp;

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

 //head=mergeSort(head);
 //head = reverseLL(head);
Node* finalHead;
 reverseRec(head,finalHead);

 PrintLL(finalHead);









}

