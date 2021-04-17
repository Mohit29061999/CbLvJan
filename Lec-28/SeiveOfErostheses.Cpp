#include <iostream>
using namespace std;


int main(){
    int n;
    cin>>n;


    int arr[n+1]={1};  ///to get one based indexing instead of 0 we have n+1 as size
    // for(int i=0;i<=n;i++)
    //    arr[i]=1;

    for(int i=0;i<=n;i++)
        cout << arr[i] << " ";
  //  arr[1]=0;
  //  arr[0]=0;

  /*  for(int i=2;i*i<=n;i++){
        if(arr[i]==1){///if it is prime then cross-out its multiple
            for(int j=i*i;j<=n;j+=i){  /// to cross-out multiples only
                arr[j]=0;
            }
        }

    }


    ///print the prime number
    for(int i=2;i<=n;i++){
        if(arr[i]==1){
            cout << i << " ";
        }
    }

    cout << endl; */
}
