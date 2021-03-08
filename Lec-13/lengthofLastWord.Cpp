//problem link: https://leetcode.com/problems/length-of-last-word/

class Solution {
public:
    int lengthOfLastWord(string s) {
        int n=s.length();
       
         int j=n-1; //ending point of last word
        while(j>=0 && s[j]==' ')
            j--;
    
        if(j<0)
            return 0;
        
        int c=0;
        while(j>=0 && s[j]!=' '){
            c++;
            j--;
            
        }
        return c;
   
    }
};