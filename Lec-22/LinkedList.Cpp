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

int main(){
 Node n1(10);
 Node n2(15);
 n1.next  = &n2;  //next of n1 is going to store address of n2
cout << n1.val << " " << (*(n1.next)).val << endl;

//whenever you have a pointer to an object use ->
cout << n1.val << " " << (n1.next)->val << endl;

}
