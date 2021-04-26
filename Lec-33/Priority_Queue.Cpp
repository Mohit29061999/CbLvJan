#include <iostream>
#include <utility>
using namespace std;

///template <typename t>
class minHeap{
    pair<int,int> *arr;    ///pair<int,int>  {priority , value}
    int cs;
    int capacity;
public:
    minHeap(int cap){
        ///crate an array in heap
        arr = new pair<int,int>[cap];
        cs=0;
        capacity=cap;
    }


     ///time complexity is O(logn)
    void push(int priority,int val){
        if(cs==capacity){
            cout << "Already Filled" << endl;
            return;
        }
          arr[cs]={priority,val};
          cs++;

          ///compare the value with its parent
          int x=cs-1; ///index of current node
          while(x>=0 && arr[x].first<arr[(x-1)/2].first){ ///parent index is (x-1)/2;
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
        if(l<cs && arr[index].first>arr[l].first)
            smallest = l;
        if(r<cs && arr[smallest].first>arr[r].first)
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
        return arr[0].second;
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
h.push(10,1);
h.push(5,2);
h.push(7,10);
h.push(20,4);
h.push(40,5);

h.pop();

while(!h.empty()){
    cout << h.top() << endl;
    h.pop();
}
}
