#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
class A{
    public:
        int a,b;
        double dist;
        A(int a1,int b1)
        {
            a=a1;
            b=b1;
            dist=sqrt(pow(a,2)+pow(b,2));
        }
    public:
        bool operator>(const A& o) const {
        return dist > o.dist;
    }
};
class Solution {
public:
    vector<vector<int> > kClosest(vector<vector<int> > points, int k) {
        int n=points.size();
        vector<vector<int> > ans;
        priority_queue<A ,vector<A>, greater<A> > min_heap;
        for(int i=0;i<n;i++)
        {
            A obj(points[i][0],points[i][1]);
            min_heap.push(obj);
        }
        for(int i=0;i<k;i++)
        {
            A obj1=min_heap.top();
            min_heap.pop();
            vector<int> t(2);
            t[0]=obj1.a;
            t[1]=obj1.b;
            ans.push_back(t);
        }
        return ans;
    }
};
int main()
{
    cout<<"Enter the size of the array"<<endl;
    int size;
    cin>>size;
    vector<vector<int> > arr;
    for(int i=0;i<size;i++)
    {
        vector<int> t(2);
        cout<<"Enter X cord:";
        cin>>t[0];
        cout<<"Enter Y cord:";
        cin>>t[1];
        arr.push_back(t);
    }
    cout<<"Enter the val of k:";
    int k;
    cin>>k;
    Solution obj;
    vector< vector<int> > ans=obj.kClosest(arr,k);
    for(int i=0;i<k;i++)
    {
        int a=ans[i][0];
        int b=ans[i][1];
        cout<<"("<<a<<","<<b<<")"<<"  ";
    }
    return 0;
}