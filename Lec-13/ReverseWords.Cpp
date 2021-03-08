//problem link: https://www.interviewbit.com/problems/reverse-the-string/

string Solution::solve(string A) {
      int n=A.length();
      
      int st=0;  //to represent starting point of a word
      
      //step 1:reverse every word
      for(int i=0;i<n;i++){
          if(A[i]==' '){
             int end =i-1; 
             
             while(st<end){
                 char temp = A[st];
                 A[st]=A[end];
                 A[end]=temp;
                 end--;
                 st++;
             }
             st=i+1; //new word is starting from i+1 index
             
          }
      }
      
      //reverse last word separately
      int end =n-1;
        while(st<end){
                 char temp = A[st];
                 A[st]=A[end];
                 A[end]=temp;
                 end--;
                 st++;
             }
      
      
      //reverse entire string
      end=n-1;
      st=0;
      while(st<end){
           char temp = A[st];
                 A[st]=A[end];
                 A[end]=temp;
                 end--;
                 st++;
      }
     
     string res="";  //making a string to store the final answer ie.without leading space ,trailing space and so on
     
     //remove starting space
     int i=0;  //i is starting point from where we should start copying
     while(i<n && A[i]==' ')
     i++;
     
     //remove trailing space
     int j=n-1; //end point of copying
     while(j>=0 && A[j]==' ')
     j--;
     
     //remove multiple space and copying string A to res
      while(i<=j){
          if(A[i]==' '){
              res+=' '; //to keep one space;
              while(i<n && A[i]==' ')
              i++;
          }
          else{
          res+=A[i];
          i++;
          }
      }
   
      return res;
    
      
      

}
