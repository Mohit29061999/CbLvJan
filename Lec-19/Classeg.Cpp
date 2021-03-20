#include <iostream>
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

    /*Student(float a2[100],float w,int r){ //there is no return type of constructor
        //name =a1;  //talking about calling object only
        weight =w;
        rollNo = r;
    } */


};

int main(){
  //create object of the class
  //Student s;  //user defined data type
  //making a variable of student datatype
  /*char arr[100]="Mohit";
  //whenever you have to access a property of a class through object
  s.name =arr;  //setting name of s object
  s.weight =70.5;
  s.rollNo = 1;

  //cout << s.name << " " << s.weight << " " << s.rollNo << endl;

  Student s1;
  s1.name =arr;
  s1.weight =65;
  s1.rollNo=2;
   cout << s1.name << " " << s1.weight << " " << s1.rollNo << endl;
    cout << s.name << " " << s.weight << " " << s.rollNo << endl; */
char arr[100]="Mohit";
char a1[100]="Rohit";
    Student s(arr,65,1,100);
    Student s1(a1,70,2,200);

    s1.rollNo =100;
   cout << s1.rollNo<< endl;

   //s1.marks=1000;
   //cout << s1.marks << endl;

     //cout << s1.name << " " << s1.weight << " " << s1.rollNo << endl;
   //cout << s.name << " " << s.weight << " " << s.rollNo << endl;
    //cout << s.marks << endl;

   s1.setMarks(1000);
   cout << s1.getMarks() << endl;


}



