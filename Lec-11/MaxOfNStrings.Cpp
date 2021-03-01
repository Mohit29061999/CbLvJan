#include<iostream>
using namespace std;

int length(char *arr){
    int count =0;
    //arr[i]!='\0'
    for(int i=0;*(arr+i)!='\0';i++)
        count++;
    return count;
}

//true-means first one greater
//else second one is greater
bool compare(char a1[],char a2[]){
    int l1=length(a1);
    int l2=length(a2);
    for(int i=0;i<min(l1,l2);i++){
        if(a1[i]>a2[i]){
            return true;
        }
        else if(a1[i]<a2[i])
            return false;
    }
    if(l1>l2)
        return true;
    else
        return false;
}

void copy(char newOne[],char old[]){
    int i=0;
    for(;old[i]!='\0';i++)
    newOne[i]=old[i];

     newOne[i]='\0';

}

int main() {
    int n;
    cin>>n;

    char arr[100];
    char max_str[100];
    cin>>max_str;  //assuming first one to be maximum
    for(int i=1;i<n;i++){
        cin>>arr;
        if(compare(max_str,arr)==false){
            //copy arr in max_str
            //copy a character array in another character arr
            copy(max_str,arr);
            //max_str=arr; //doesn't works for character array
        }
    }
    cout << max_str << endl;
	return 0;
}




