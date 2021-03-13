#include <iostream>
using namespace std;


void toh(int n,char src,char help,char dest){
    //base case
    if(n==0)
        return;

    //move n-1 disk from src to help using dest
    toh(n-1,src,dest,help);

    //move nth disk from src to dest
    cout << "Moving "<< n << "th disk from "  << src << " to " << dest << endl;

    //move n-1 disk from help to dest using src
    toh(n-1,help,src,dest);

}


int main(){

toh(3,'S','H','D');  //'S'-means src rod 'H'-means help rod 'D'-means dest rod

}




