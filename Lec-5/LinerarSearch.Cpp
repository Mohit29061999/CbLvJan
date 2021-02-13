#include <iostream>
using namespace std;


int main(){
     int n;
     cin>>n;

     int arr[n];
     for(int i=0;i<n;i++){
        cin>>arr[i];
     }

     int key;
     cin>>key;   //key represent value to be searched

    // bool f=false;
     int i;
     for(i=0;i<n;i++){
        if(arr[i]==key){
              //  f=true;
            cout << "Key Found at " << i << endl;
          return 0; //exit main or terminate the program
         // break;
        }
     }

 //if(flag ==false || i==n){
   // cout << "Not exist"
 //}

     //if at reach at this point,can i say for sure that value doesn't exist????
     cout << "Not Found" << endl;
}



