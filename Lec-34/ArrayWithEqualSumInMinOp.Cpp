//problem link: https://leetcode.com/problems/equal-sum-arrays-with-minimum-number-of-operations/

class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        ///Not possible case
        int n=nums1.size();
        int m=nums2.size();

        if(n*1>m*6 || n*6<m*1)
            return -1;

        priority_queue<int> pq1; //max heap
        priority_queue<int,vector<int>,greater<int>>pq2; //min heap

        int s1=0;
        for(int i=0;i<n;i++)
            s1+=nums1[i];

          int s2=0;
        for(int i=0;i<m;i++)
            s2+=nums2[i];

        int s3=0;  //s3 is storing sum of pq1 (max heap)
        int s4=0;  //s4 is storing sum of pq2(min heap)
        if(s1>s2){
            ///inserting the elements of nums1 to max heap
            for(int i=0;i<n;i++)
                pq1.push(nums1[i]);
             ///inserting the elements of nums2 to min heap
            for(int i=0;i<m;i++)
                pq2.push(nums2[i]);

            s3=s1;
            s4=s2;
        }
        else{
               ///inserting the elements of nums1 to min heap
            for(int i=0;i<n;i++)
                pq2.push(nums1[i]);
             ///inserting the elements of nums2 to min heap
            for(int i=0;i<m;i++)
                pq1.push(nums2[i]);

            s3=s2;
            s4=s1;

        }

        int ans =0;
        while(s3!=s4){
            ///taking the max element of array with greater sum
            int x=pq1.top();
             ///taking the min element of array with less sum
            int y=pq2.top();

            ///see if we can make them equal in this step
            int diff = abs(s3-s4);

            if(x-1>=diff || 6-y>=diff)
                return ans+1;

            ///check whether converting x to 1 is better or y to 6
            if(x-1>=6-y){
                ///convert x to 1
                pq1.pop();
                pq1.push(1);
                s3-=(x-1);
            }
            else{
                ///convert y to 6
                pq2.pop();
                pq2.push(6);
                s4+=(6-y);
            }
        ans++;
        }
       return ans;
    }
};
