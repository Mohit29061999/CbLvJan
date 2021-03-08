#include <iostream>
using namespace std;



void intToString(int n,string arr[]){
    //base case
    if(n==0)
        return;

    int x=n%10; //storing the last digit
    intToString(n/10,arr); //one less digit
    cout << arr[x] << " ";


}




int main(){
   string arr[10]={"zero","one","two","three","four","five","six","seven","eight","nine"};

    intToString(2034,arr);
}




