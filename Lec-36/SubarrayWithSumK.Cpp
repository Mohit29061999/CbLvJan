///problem link: https://leetcode.com/problems/subarray-sum-equals-k/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>m;  ///number of times a particular prefix sum
                                  ///is coming
        int ans =0;
        int sum=0; ///to store prefix sum
        int n=nums.size();

        for(int i=0;i<n;i++){
            ///try every index as your ending index of the subarray
            ///find starting point that will give sum = k
            sum+=nums[i];
            if(sum==k)
                ans++; //found a subarray with sum k
            int y=sum-k; ///find starting point so that
                         ///they have sum k
            if(m.find(y)!=m.end())
                ans+=m[y];
            //m[sum]++;
            if(m.find(sum)!=m.end()){
                m[sum]++;
            }
            else
                m.insert({sum,1});

        }
        return ans;

    }
};
