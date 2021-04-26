//problem link: https://www.interviewbit.com/problems/merge-k-sorted-arrays/


class Node{
    public:
    int val;
    int x;  ///x value will tell us array no
    int y;  ///index in that particular array

    Node(int a,int b,int c){
        val =a;
        x=b;
        y=c;
    }

};

///create a min heap
class customClass{
    public:
    bool operator()(Node n1,Node n2){
        ///return true when i wan't to swap them
        return n1.val>n2.val;

    }

};


vector<int> Solution::solve(vector<vector<int> > &A) {
    priority_queue<Node,vector<Node>,customClass>pq;
    int n=A.size();  ///no of arrays

    ///insert the first value of all the array in the min heap
    for(int i=0;i<n;i++){
        Node temp(A[i][0],i,0);
        pq.push(temp);
    }

    vector<int>ans;
    while(!pq.empty()){
        ///store the current min in the vector
        Node temp = pq.top();
        pq.pop();
        ans.push_back(temp.val);

        int x=temp.x;  ///array no of current value
        int y=temp.y;   ///index no of current value

        ///insert the next value in the priority_queue if it exists
        int m=A[x].size(); ///m  is representing size of current array
        if(y+1<m){
            Node n1(A[x][y+1],x,y+1);
            pq.push(n1);
        }

    }

    return ans;

    }


