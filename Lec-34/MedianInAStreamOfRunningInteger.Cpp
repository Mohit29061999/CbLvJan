//problem link: https://leetcode.com/problems/find-median-from-data-stream/


class MedianFinder {
    ///we want :
    /// 1. abs(size of pq1 - size of pq2)<=1
    /// 2. pq1.top()<=pq2.top()
    priority_queue<int>pq1; ///max heap
    priority_queue<int,vector<int>,greater<int>>pq2;  ///min heap
    int size;  ///number of elements in both the heap combined
    int turn;  ///to add the new element to min heap or to max heap
public:
    /** initialize your data structure here. */
    MedianFinder() {
        size=0;
        turn =1; ///1 means add to max heap else to min heap
    }

    ///time complexity is O(logn) for each add
    ///add a new number to your data structure
    void addNum(int num) {
        size++; ///inserting a new element
        ///when new number should be added to max heap
        if(turn ==1){
            if(!pq2.empty() && pq2.top()<num){
                ///insert it to min heap first
                pq2.push(num);
                ///insert the minimum element from min heap to max heap
                int x=pq2.top();
                pq2.pop();
                pq1.push(x);
            }
            else{
                ///directly insert it to max heap
                pq1.push(num);
            }
            turn =0;
        }
        else{
            ///insert it to min heap
            if(!pq1.empty() && pq1.top()>num){
                ///insert it to max heap
                pq1.push(num);

                ///shift the top element from pq1 to pq2
                int x=pq1.top();
                pq1.pop();
                pq2.push(x);
            }
            else{
                  ///directly insert it to min heap
                pq2.push(num);
            }
            turn =1;
        }
    }

    ///give you the median till this point
    double findMedian() {
        ///check if size is odd or even
        if(size%2==1){
            ///give the root element of max heap
            return pq1.top();
        }
        else{
            ///return average of the top of two
            double ans= (pq1.top()+pq2.top())/2.0;
            return ans;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
