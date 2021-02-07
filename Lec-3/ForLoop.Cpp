#include <iostream>
using namespace std;


int main(){
 /* int n;
  cin>>n; */

 /* int i=1;

  for(    ;  ;   ){
    //some repeated task
    cout << i << " ";
    i=i+1;  //update it here
    //write condition here


  } */


  //break
  /*for(int i=1;i<=5;i++){
    for(int j=1;j<=5;j++){
        if(j==3)
            break;
        cout << j << " ";
    }
    cout << endl;
  } */

  /*if(0)
    cout << "0 is true" << endl;
  else
    cout << "0 is false" << endl;

  if(-1)
    cout << "-1 is true" << endl;
  else
    cout << "-1 is false" << endl; */

    //continue
   /* for(int i=1;i<=10;++i){
            cout << i << " ";
        if(1)
            continue;  //we will skip all the lines after continue;
       // cout << i << " "; //we won't reach here for i==4
    } */

    /*int i=1;
    while(i<10){
                        cout << i << " ";
        if(i==4)
            continue;  //infinite loop
        i=i+1;  //for i==4 this won't get exceuted
    } */

  /*  int i=1;
    for(;i<=3;i++){
        if(i==2)
            break;
    }
    //after break we reach here
    cout << i << endl; */

   /* int i=10;
    do{
        cout << i  << "in do while"<< " ";
        i=i+1;
    }
    while(i<0);

    //what is min number of times that a do while loop is going to run

    i=10;
    while(i<0){
         cout << i  << "in  while"<< " ";
        i=i+1;
    } */

    for(int i=0;i<10;i++){
            cout << i << endl;
            if(i==4)
            continue;
           // i=i+1;
       // cout << i << " in for loop";
    }



}

