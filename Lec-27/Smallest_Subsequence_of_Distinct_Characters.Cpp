//problem link: https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/

class Solution {
public:
    string smallestSubsequence(string s) {
        int count[256]={0};
        int used[256]={0};

        int n=s.length();

        stack<char>s1;

        for(int i=0;i<n;i++)
            count[s[i]]++;

        for(int i=0;i<n;i++){
            ///this character is no longer a part of the remaining string
            count[s[i]]--;

            ///already occurred don't include it
            if(used[s[i]])
                continue;


            ///check if we can replace some characters by the current character
            while(!s1.empty() && count[s1.top()] && s1.top()>s[i]){
                used[s1.top()]=0;
                s1.pop();
            }

            s1.push(s[i]);
            used[s[i]]=1;

        }

        string str="";
        while(!s1.empty()){
            str+=s1.top();
            s1.pop();
        }

        ///reverse the string
        reverse(str.begin(),str.end());
        return str;
    }
};
