#include <iostream>
using namespace std;

//making a template with name T to act as placeHolder
template <typename T>
class Vector{
    public:
        int cs; //number of elements currently in array
        int ms;  // max elements that can be stored in array
        T* arr;

        Vector(int m=2){
            ms =m;
            cs=0;
            arr=new T[ms]; //creating array using dma
        }

        //push_back(val)
        void push_back(T val){
            //check if array is filled or not
            if(cs==ms){
                //double the size
                T* old=arr;
                arr=new T[ms*2]; //creating an array of twice the size
                //copy contents from old array to new array
                for(int i=0;i<cs;i++)
                    arr[i]=old[i];
                ms=ms*2;

                //delete the previous array
                delete []old;
                old=NULL;
            }

            arr[cs]=val;
            cs++;
        }

        void pop_back(){
            //try: whenever half of the array is empty ,reduce size by half
            if(cs>0){
                cs--;
            }
        }

        //how many elements that we have in vector
        int size(){
            return cs;
        }

        //operator overload for []
        T operator[](int i){
            return arr[i];
        }



};


int main(){
    Vector<int> v(10); //int is type of vector and all T they are going to be replaced with int

    for(int i=0;i<5;i++)
        v.push_back(i+1);

         for(int i=0;i<5;i++)
           cout << v[i] << " ";  //arr[i] to  v[i]

    //cout << v.ms  << endl;
    for(int i=0;i<5;i++)
    v.pop_back();

    cout << v.size() << endl;

}
