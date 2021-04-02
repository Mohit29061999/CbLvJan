#include <iostream>
#include <list>  //header file for stl of linked list
using namespace std;




int main(){
    list<int> l; //create a linked list

    //insert at start
    l.push_front(1);

    //insert at end
    l.push_back(4);
    l.push_back(2);
    l.push_back(1);
    l.push_back(5);

    //delete at front
    l.pop_front();

    //delete at end
    l.pop_back();

    //to print ll
    int n=l.size();  //no of elements in ll
  //  for(int i=0;i<n;i++)
    //    cout << l[i] << " ";  //not valid as linked list is non-continous

    list<int>::iterator i;  //creating an iterator
                       //it is a pointer to travel through ds

    l.sort();  //to sort the linked list
    //begin() gives the address of head and end() gives you null or ending address
    for(i=l.begin();i!=l.end();i++){  //i is storing the address of current node
        cout << *i << " ";
    }

    cout << endl;

    l.reverse();
    cout << "after reversing" << endl;
    for(i=l.begin();i!=l.end();i++){  //i is storing the address of current node
        cout << *i << " ";
    }

    cout << endl;

    i=l.begin(); //address of head
    i++;  //curr = curr->next;
    cout << *i << endl;




}
