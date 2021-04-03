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

class Queue{
    Node* head;
    Node* tail;
    //head is pointing to first element of ll
                      //tail is pointing to last element of ll
    int cs;
public:
    Queue(){
        cs=0;
        head=NULL;
        tail =NULL;
    }

    void push(int val){
        //if it is the first element
        Node* n =new Node(val);
        cs++;
        if(head==NULL){
            head=tail = n;
            return;
        }
        tail->next =n;
        tail =n;
    }

    void pop(){
        if(cs>0){
            cs--;
            //deleting the only left element
            if(head->next==NULL){
                    delete head;
                head=tail =NULL;
                return;
            }

            Node* n =head;
            head=head->next;
            delete n;


        }
    }

    int size(){
        return cs;
    }

    int front(){
        return  head->val;
    }

    bool empty(){
        return head==NULL;
    }
};



int main(){

Queue q;
q.push(1);
q.push(2);
q.push(3);
q.push(4);

while(!q.empty()){
    cout << q.front() << " ";
    q.pop();
}




cout << q.size() << endl;
}


