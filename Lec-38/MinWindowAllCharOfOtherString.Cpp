///problem link: https://leetcode.com/problems/minimum-window-substring/

class Solution {
public:
    string minWindow(string s, string t) {
            int c2[256]={0};
        for(int i=0;i<t.length();i++)
            c2[t[i]]++;

        int c1[256]={0};

        int st=0; ///start of current window
        int l=INT_MAX;  ///length of min substring
        int s1=0;   /// starting index of substring

        for(int i=0;i<s.length();i++){  ///trying every index as your ending index
            c1[s[i]]++;

            ///whether i have all the characters in this window or not
            bool hasAll = true;
            for(int i=0;i<256;i++){
                if(c1[i]<c2[i]){
                    hasAll = false;
                    break;
                }
            }

            if(hasAll==true){
                ///you have all the characters now you have to reduce the size of the window
                while(c1[s[st]]>c2[s[st]]){
                    c1[s[st]]--;
                    st++;
                }

                if(l>i-st+1){
                    l=i-st+1;
                    s1=st;
                }
            }

        }
        string res="";
        if(l==INT_MAX){
            return res;
        }

        ///return string from s1 index and of length l
        for(int i=0;i<l;i++){
            res+=s[s1+i];
        }
        return res;
    }
};
