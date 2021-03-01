#include<iostream>
using namespace std;

int length(char *arr){
    int count =0;
    //arr[i]!='\0'
    for(int i=0;*(arr+i)!='\0';i++)
        count++;
    return count;
}

int main() {
    int n;
    cin>>n;
    char arr[100];
    cin>>arr;

    //step1:move every character n position to the right starting from end
    int l=length(arr);
    for(int j=l-1;j>=0;j--)
        arr[j+n]=arr[j];

    //step 2: copy character from len in 0 to n-1
    int j=l;
    for(int i=0;i<n;i++){
        arr[i]=arr[j];
        j++;
    }

    arr[l]='\0';


    cout << arr << endl;
}





