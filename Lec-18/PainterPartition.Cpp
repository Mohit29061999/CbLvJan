using namespace std;

bool canPaintWithinXTime(int arr[],int n,int k,int x){
    int p_used=1; //no of painter required
    int time_spend=0;  //current painter time used
    for(int i=0;i<n;i++){
        if(arr[i]>x)
        return false;

        //current painter ko ye kaam de skte h
        if(arr[i]+time_spend<=x){
            time_spend +=arr[i]; //current painter ko hi kaam do
        }
        else{
            //new painter ko ye kaam do
            p_used++;
            time_spend = arr[i];
        }
    }

    if(p_used<=k)
    return true;
    return false;

}

int main() {
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
	    int k;  //no of painters
	    cin>>k;
	    int n; //no of boards
	    cin>>n;

	    int arr[n];
	    for(int i=0;i<n;i++)
	    cin>>arr[i];

	    int ans =INT_MAX;

	   int min_v=0; //minimum time possible
	   int max_v=0;       //maximum time possible
	   for(int i=0;i<n;i++){
	   min_v=max(min_v,arr[i]);
	   max_v+=arr[i];
	   }

	    while(min_v<=max_v){
	        int mid = (min_v+max_v)/2;
	        //kya mid ya usse smaller value possible h
	        if(canPaintWithinXTime(arr,n,k,mid)==true){
	            //right side value ko discard karna h
	            ans = mid;
	            max_v=mid-1;

	        }
	        else{
	            //left values should be discarded
	            min_v=mid+1;
	        }
	    }

	    cout << ans << endl;


	}
	return 0;
}
