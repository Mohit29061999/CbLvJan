#include <iostream>
using namespace std;

class Node{
public:
    int val;
    Node* next;

    Node(int v){
        val = v;
        next=NULL;
    }
};

class Stack{
   Node* head;  ///head of linked list;
   int cs;
   public:
       Stack(){
           head=NULL;
           cs=0;
       }

       void push(int v){
           //logic for insert at start
           cs++;
           Node* n =new Node(v);
           if(head==NULL){
              head=n;
              return;}

           n->next = head;
           head=n;
           return;
       }

       void pop(){
          if(cs>0){
            ///if this was your last element then head =NULL
            cs--;
            if(head->next==NULL){
                //Node* n =head;
                //head=NULL;
                delete head;
                head=NULL;
                return;
            }
            Node* n =head;
            head=head->next;
            delete n;
            return;

          }
          cout << "Already Empty" << endl;
       }

       bool empty(){
          return head==NULL;
       }

       int top(){
           return head->val;
       }

       int size(){
           return cs;
       }


};

int main(){
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
      s.push(4);

   // cout << v[v.size()-1] << endl;

      while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
      }

      cout << s.size() << endl;





}

