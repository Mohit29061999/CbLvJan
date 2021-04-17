//problem link: https://leetcode.com/problems/sliding-window-maximum/



class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>dq;

        int n=nums.size();
        vector<int>ans;
        ///store elements of first window
        for(int i=0;i<k;i++){
            ///remove useless value ie.value which are in  left and are smaller
            while(!dq.empty() && nums[dq.back()]<=nums[i])
                dq.pop_back();
            dq.push_back(i);
        }

        ///insert the answer for first window
        ans.push_back(nums[dq.front()]);

        ///do the same task for rest of the window
        for(int i=k;i<n;i++){
            ///remove all the elements that are not part of this window
            int s=i-k+1; ///starting point of current window ie.ends at ith index

            ///remove elements that are not part of this window
            while(!dq.empty() && dq.front()<s)
                dq.pop_front();

              ///remove useless value ie.value which are in  left and are smaller
            while(!dq.empty() && nums[dq.back()]<=nums[i])
                dq.pop_back();

              dq.push_back(i);

                 ///insert the answer for this window
        ans.push_back(nums[dq.front()]);




        }

        return ans;
    }
};
