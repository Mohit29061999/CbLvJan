#include <iostream>
using namespace std;


class Car{
public:
    int x;

    Car(int x){
        //this pointer is used
        //
       // (*this).x=x;   //calling object.x=argument x;
       this->x=x;   //when you have a pointer to an object then you directly access
                     //the property of object using ->
    }

    Car* ReturnAddressOfCallingObject(){
        return this;
    }
};

int main(){
    Car c(4);
   // cout << c.x << endl;
   Car* c1=c.ReturnAddressOfCallingObject();

   //cout << (*c1).x << endl;
   cout << c1->x << endl;
}
