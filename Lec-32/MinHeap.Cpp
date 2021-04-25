#include <iostream>
using namespace std;


class minHeap{
    int *arr;
    int cs;
    int capacity;
public:
    minHeap(int cap){
        ///crate an array in heap
        arr = new int[cap];
        cs=0;
        capacity=cap;
    }


     ///time complexity is O(logn)
    void push(int val){
        if(cs==capacity){
            cout << "Already Filled" << endl;
            return;
        }
          arr[cs]=val;
          cs++;

          ///compare the value with its parent
          int x=cs-1; ///index of current node
          while(x>=0 && arr[x]<arr[(x-1)/2]){ ///parent index is (x-1)/2;
            swap(arr[x],arr[(x-1)/2]);
            x=(x-1)/2;
          }
    }

    ///time complexity is O(logn)
    void minHeapify(int index){
        int smallest = index; ///parent should be the smallest
        int l=index*2+1;
        int r=index*2+2;
        ///find smallest of parent,left and right child
        if(l<cs && arr[index]>arr[l])
            smallest = l;
        if(r<cs && arr[smallest]>arr[r])
            smallest = r;
        if(smallest!=index){
            ///swap the parent with one of its child
            swap(arr[smallest],arr[index]);
            minHeapify(smallest);
        }

    }
    void pop(){
        ///removes the element with the highest priority
        ///remove the element at the start of the array
        if(cs==0){
            cout << "No element" << endl;
            return;
        }

        swap(arr[0],arr[cs-1]);
        cs--;

        ///restore the minHeap prop
        minHeapify(0);

    }


    ///time complexity is O(1)
    int top(){
        return arr[0];
    }

    int size(){
        return cs;
    }

    bool empty(){
        ///return cs==0;
   if(cs==0)
    return true;
   else
    return false;
    }

};

int main(){
minHeap h(10);
h.push(3);
h.push(2);
h.push(15);
h.push(4);
h.push(45);

h.pop();

while(!h.empty()){
    cout << h.top() << endl;
    h.pop();
}
}
