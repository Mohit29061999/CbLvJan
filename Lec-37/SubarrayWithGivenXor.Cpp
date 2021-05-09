///problem link: https://www.interviewbit.com/problems/subarray-with-given-xor/


int Solution::solve(vector<int> &A, int B) {
    int ans =0;
    int n=A.size();

    int p_xor =0; ///to calculate fro every index
    map<int,int> m ;  ///to store count of particular prefix xor
    for(int i=0;i<n;i++){  ///try all index as my ending index of subarray
       ///calulate prefix xor till ith index
       p_xor = p_xor ^ A[i];

       if(p_xor ==B){
           ///xor from 0th index to ith index is equal to B
           ans++;
       }

       int y=p_xor ^B;
       if(m.find(y)!=m.end()){
           //index with prefix_xor = y ,index after can be starting point of subarray
           ///so that xor[index+1: ith ]=B
           ans+=m[y];
       }

       m[p_xor]++;

    }
    return ans;



}

