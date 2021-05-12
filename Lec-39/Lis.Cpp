//problem link: https://leetcode.com/problems/longest-increasing-subsequence/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        int dp[n];  ///dp[i]:max length subsequence in strictly increasing order ending at ith index
        dp[0]=1;

        for(int i=1;i<n;i++){
            dp[i]=1;  ///ith element alone
            ///check for index that can be placed before ith index
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i] && dp[j]+1>dp[i]){
                    dp[i]=dp[j]+1;
                }
            }

        }

        int ans =0;
        int end_index = -1;
        vector<int>v;  ///to print the subsequence
        for(int i=0;i<n;i++){
            if(ans<dp[i]){
                ans = dp[i];
                end_index = i;
            }
        }

         v.push_back(nums[end_index]);
        ans--; //now we need to find ans-1 values to place before last value
        end_index--;
        while(end_index>=0 && ans>0){
            if(dp[end_index]==ans && nums[end_index]<v[v.size()-1]){
                v.push_back(nums[end_index]);
                ans--;
            }
            end_index--;
        }

        for(int i=v.size()-1;i>=0;i--){
            cout << v[i] << " ";
        }

        return v.size();

    }
};
