//problem link: https://leetcode.com/problems/longest-palindromic-substring/


class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length();
        bool dp[n][n];
        int start=0;
        int ans =1;
        ///fill all substring of length 1
        for(int i=0;i<n;i++)
            dp[i][i]=true;

        ///fill all substring of length 2
        for(int i=0;i<n-1;i++){
            if(s[i]==s[i+1]){
                dp[i][i+1]=true;
                ans = 2;
                start = i;
            }
            else
                dp[i][i+1]=false;
        }

        ///fill the rest of the table
        for(int l = 3;l<=n;l++){
            for(int start_i=0;start_i<=n-l;start_i++){
                int end_i=start_i+l-1;
                ///check if substring s[start_i:end_i] is palindrome or not
                if(s[start_i]==s[end_i]){
                    dp[start_i][end_i]=dp[start_i+1][end_i-1];
                    if(dp[start_i][end_i]==true){
                        ans = l;
                        start = start_i;
                    }
                }
                else{
                    dp[start_i][end_i]=false;
                }
            }
        }

        string res="";
        for(int i=0;i<ans;i++){
            res+=s[start+i];
        }
        return res;



    }
};
