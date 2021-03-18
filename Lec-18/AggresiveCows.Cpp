#include <bits/stdc++.h>
using namespace std;


//tells us whether min dist x or more  possible or not
bool canPlaceWithX(int arr[],int n,int x,int c){
    //min distance x ya x se greater possible h???
    int cowPlaced=1;  //first cow is at arr[0];
    int last = arr[0];  //last placed cow position

    for(int i=1;i<n;i++){
        if(arr[i]-last>=x){
            cowPlaced++;
            last=arr[i];
        }

       //else  can't place cow here
    }
    if(cowPlaced>=c)  //all cows placed
    return true;
    else
    return false;
}

int main(){
  int n;  //no of possible location
  cin>>n;
  int c;
  cin>>c;  //no of cows

  int arr[n];
  for(int i=0;i<n;i++)
  cin>>arr[i];

  sort(arr,arr+n);

  int ans =INT_MIN;
  int min_v=1;  //min possible value
  int max_v=n-1;  //max possible value
  while(min_v<=max_v){
      int mid =(min_v+max_v)/2;

      //ask if ans greater than or equal to mid is possible or not
      if(canPlaceWithX(arr,n,mid,c)){
          //0 to mid-1 shouldn't be checked
          ans = mid;
          min_v=mid+1; //mid+1 to max_v
      }
      else{
          //try values from min_v to mid-1;
          max_v=mid-1;
      }
  }
  cout << ans << endl;





}
