///problem link: https://leetcode.com/problems/subarrays-with-k-different-integers/


int solve(vector<int> &v,int k){
     int n=v.size();
        int ans =0;
        int c=0;  ///to store count of distinct element in current window

        map<int,int> m;  ///to store count of an integer in current window

        int st=0;   ///starting point of the window

    for(int i=0;i<n;i++){
        ///one by one add all subarray ending at ith index
        ///check if this element is new in current window
        if(m.find(v[i])==m.end())
            c++; ///this integer is coming first time so distinct count should increase

        m[v[i]]++;
        ///we want at most k distinct elements so if we have
        ///more than k distinct elmenets, then we need to shift the starting point of window
        ///to right
        while(c>k){
           m[v[st]]--;
            if(m[v[st]]==0){
                c--; ///this element is no longer present in the window
                m.erase(v[st]);
            }
            st++; ///shift window to right
        }

        ans+=(i-st+1);  ///add all subarray ending at ith index
    }

    return ans;
}

class Solution {
public:
    int subarraysWithKDistinct(vector<int>& A, int K) {
        ///subarray with k distinct = subarray with atmost k distinct - subarray with at most k-1 distinct
       return solve(A,K)-solve(A,K-1);
    }
};
