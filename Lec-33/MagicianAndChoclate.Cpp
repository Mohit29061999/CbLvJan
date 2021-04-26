

//problem link: https://www.interviewbit.com/problems/magician-and-chocolates/

int mod =1000000007;

int Solution::nchoc(int A, vector<int> &B) {
 long long  int ans =0;
    priority_queue<int>pq;
    int n=B.size();
    for(int i=0;i<n;i++){
        pq.push(B[i]);

    }

    while(A>0){
        ans +=(pq.top());
      //ans  = ans%mod;
        int x=pq.top();
        pq.pop();
        pq.push(x/2);
        A--;
    }

    return ans%mod;

}


