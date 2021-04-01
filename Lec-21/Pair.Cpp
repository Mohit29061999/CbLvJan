#include<iostream>
#include<vector>//using stl vector
using namespace std;
template <typename T1,typename T2>
class Pair{
public:
    T1 first;
    T2 second;

    Pair(T1 f,T2 s)
    {
        first=f;
        second=s;
    }

bool operator<(Pair<T1,T2 > p2  )
{

    if(first<p2.first)
        return true;
    else if(first>p2.first)
        return false;

    return second<p2.second;
}

    };


int main ()
{
    Pair<char, int > p('c',97);

    cout<<p.first<<"  "<<p.second<<endl;

Pair<char, int > p2('d',98);

if(p<p2)
{
cout<<"p2 is greater  "<<endl;
}
else
    cout<<" p2 is smaller "<<endl;
}
