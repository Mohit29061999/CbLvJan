#include<iostream>
using namespace std;

int length(char *arr){
    int count =0;
    //arr[i]!='\0'
    for(int i=0;*(arr+i)!='\0';i++)
        count++;
    return count;
}

bool isPaindrome(char *arr){
    int i=0;
    int j=length(arr)-1; //indexing is 0 length
    while(i<j){
            //check if ith character is equal to jth character
            //arr[i]==arr[j[
        if(*(arr+i)!=*(arr+j)){
            return false;
        }
        i++;
        j--;
    }
    return true;
}

int main() {
    char arr[]="abcd";
    if(isPaindrome(arr))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    //cout << length(arr) << endl;
	return 0;
}



