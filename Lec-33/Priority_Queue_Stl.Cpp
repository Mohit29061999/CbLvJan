#include <iostream>
#include <queue> ///or #include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int x;
    int y;

    Node(int a,int b){
        x=a;
        y=b;
    }




};



class customComparator{
    public:
    bool operator()(Node n1,Node n2){  ///n1 is parent and n2 is child
        ///write the logic here assuming that true means swap here and false no swap
        return n1.x>n2.x;
    }
};




int main(){
    ///by default priority_queue is max heap
    ///priority_queue<int>pq;
    /*priority_queue<>pq;  ///second way to convert max to min heap
    pq.push(4);
    pq.push(10);
    pq.push(1);
    pq.push(15);
    pq.push(5);
    ///to convert it to min heap,insert the negative values
 /*   pq.push(-4);
    pq.push(-10);
    pq.push(-1);
    pq.push(-15);
    pq.push(-5); */

    priority_queue<Node,vector<Node>,customComparator>pq;

    Node n(1,5);
    pq.push(n);
    Node n1(0,10);
    pq.push(n1);
    Node n2(-4,10);
    pq.push(n2);


    while(!pq.empty()){
        cout << (pq.top()).x  <<" " << (pq.top()).y<<endl;
        pq.pop();
    }
}


