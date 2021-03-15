#include <iostream>
using namespace std;

//false means don't swap else swap
bool shouldSwap(char arr[],int s,int e){
    for(int j=s;j<e;j++){
        if(arr[j]==arr[e])
            return false;
    }

    return true;
}

void permutation(char arr[],int i){ //index at which you are deciding the character
    //base case
    if(arr[i]=='\0'){
        cout << arr << endl;
        return;
    }

    for(int j=i;arr[j]!='\0';j++){ //try all characters for ith index
            if(shouldSwap(arr,i,j)){
            swap(arr[i],arr[j]); //make jth character as ith character
            permutation(arr,i+1); //now fix rest of characters

             swap(arr[j],arr[i]); //backtracking step making it same as original one
            }

    }


}


int main(){
    char arr[100];
    cin>>arr;

    permutation(arr,0);

}
