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


Node* reverseKGroup(Node* head,int k){
	//base case
	if(head==NULL)
	return head;

	Node* curr=head;
	//get the kth node from this node which is going to be our new starting point
	for(int i=0;i<k;i++)
	curr=curr->next;

	Node* restHead=reverseKGroup(curr,k);  //except first k , recursion will reverse the rest

   //reverse the current k nodes
   int c=0;
   Node* prev=NULL;
   curr=head;


  //reversing first k nodes
   while(c<k){
	   //reverse the current node
	   Node* n = curr->next;

	   curr->next = prev;
	   prev = curr;
	   curr= n;
	   c++;
   }

   head->next = restHead;  //after reversing head is pointing to last node of current k nodes

   return prev;



}

















//write delete at any postion
int main(){
 Node* head =NULL;  //this is going to store the address of first element of linked list


  int n,k;
  cin>>n>>k;

  for(int i=0;i<n;i++){
	  int x;
	  cin>>x;
	  insertAtEnd(head,x);
  }


 head= reverseKGroup(head,k);

  PrintLL(head);








}
