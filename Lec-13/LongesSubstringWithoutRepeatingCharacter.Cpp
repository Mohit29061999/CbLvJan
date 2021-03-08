//problem link: https://leetcode.com/problems/longest-substring-without-repeating-characters/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        int ans=0;
        int st=0;  //starting point of substring
        int freq[256]={0};
        for(int i=0;i<n;i++){  //to try every index as my ending index
            //can i include current element in my substring or not
            while(freq[s[i]]>0){
                //move starting point one step ahead
                freq[s[st]]--;
                st++;
            }
            
            //include ith character 
            freq[s[i]]++;
            ans = max(ans,i-st+1);
            
        }
        
        return ans;
    }
};