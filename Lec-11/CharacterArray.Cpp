#include<iostream>
#include <bits/stdc++.h>
#include <cstring>
using namespace std;

int length(char arr[]){
    int count =0;
    for(int i=0;arr[i]!='\0';i++)
        count++;
    return count;
}

void take(char arr[],int max_size,char end){
    int i=0;  //position where current character is to be stored
    char ch;
    ch = cin.get();
    while(ch!=end){
        arr[i]=ch;
        i++;
        if(i==max_size-1)
            break;
        ch = cin.get();
    }
    arr[i]='\0';


}
int main() {
    //length doesn't include null character
   // char arr[10]={'a','b','c','d'}; //null means end of character array
   /*  for(int i=0;i<4;i++)
        cout << arr[i];
     cout << endl;*/
     char arr[100];
     take(arr,100,'\n');
     //cin thinks space to be end of string as well
   // cin.getline(arr,100);
     //cin>>arr;  //no need to add NULL it will be get automatically added
     //string: a set of characters terminated by null
    // char arr[]="abcd";  //complier adds '\0' on its own
     //cout << sizeof(arr) << endl;
    // int arr[]={1,2,3,4};
     cout << arr << endl;  //address of 0th element
    // cout << length(arr) << endl;
    cout << strlen(arr) << endl;
	return 0;
}

