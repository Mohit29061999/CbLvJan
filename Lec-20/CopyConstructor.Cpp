#include <iostream>
#include <cstring>  //file for cstring
using namespace std;

//this is just a blueprint
//this is just a datatype
class Student{
private:  //by default things are private in class
    int marks; //can't access this from outside of the class
public:
    //char name[100];
    char *name;
    //string name;
    int rollNo;
    float weight;

    //default constructor
    Student(){ //there is no return type of constructor


    }

    //getter function:to get value of a parivate variable
    int getMarks(){
        return marks;
    }

    //setter function:to set a private variable
    void setMarks(int m){
    marks =m;
    }




    //can have more than one constructor
    //default constructor
    Student(char a1[100],float w,int r,int m){ //there is no return type of constructor
        name =a1;  //talking about calling object only
        weight =w;
        rollNo = r;
        marks = m;
    }
  //there is a default copy constructor too
 /*   Student(Student &x){ //copy properties of x object
        name =x.name;  //name corresponds to object which is created
        weight = x.weight;
        rollNo = x.rollNo;
        marks = x.marks;

    } */

    //deep copying copy constructor
        Student(Student &x){ //copy properties of x object
        //create a new address
        name = new char[100];
        strcpy(name,x.name);  //inbuilt function for copying contents from one character array to another

        weight = x.weight;
        rollNo = x.rollNo;
        marks = x.marks;

    }

    //complier automatically adds a default operator for =
    //operator overloading
    void operator=(Student x){ //from which object to copy
      //name = s.name;
      name = new char[100];
       strcpy(name,x.name);
        weight = x.weight;
      rollNo = x.rollNo;
        marks = x.marks;
    }

    void operator+(Student x){
        rollNo-=x.rollNo;
        marks-=x.marks;
        weight -=x.weight;

    }

 /*   Student operator+(const Student &x){
        Student s3;
        s3.rollNo=rollNo+x.rollNo;
        return s3;
    } */


    //no by default code for +,-,*,%

    /*Student(float a2[100],float w,int r){ //there is no return type of constructor
        //name =a1;  //talking about calling object only
        weight =w;
        rollNo = r;
    } */


};

int main(){

char arr[100]="Mohit";
char a1[100]="Rohit";
    Student s(arr,65,1,100);  //constructor will allocate memory to object so in a way it will create the object
    Student s1(a1,70,2,200);

    //Student s2(s);  //this will call copy constructor
    Student s2=s; //this will also call copy constructor

   //create another object from s
   //cout << s2.name << " "<< s2.weight << " " << s2.rollNo << s2.getMarks() <<endl;
   //s2.name[0]='H';
   //cout << s.name << endl;

   Student s3;  //object is already created
   //s3=(s);  //s3 is calling = with s as an argument
    s3=s; //assignment operator
  s+(s1);
  //s+s1;    //x+y
  cout << s.rollNo << " " << s.weight << endl;

  //cout << s4.rollNo << endl;




}




