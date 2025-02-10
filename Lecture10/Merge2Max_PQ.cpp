//merge 2 max priority_queue to get a new priority queue

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main()
{
    priority_queue<int> q1;
    priority_queue<int> q2;
    cout<<"Enter the size of queue1,queue2";
    int n1,n2;
    cin>>n1>>n2;
    cout<<"Enter elements of queue1"<<endl;
    int a;
    for(int i=0;i<n1;i++)
    {
        cin>>a;
        q1.push(a);
    }
    for(int i=0;i<n1;i++)
    {
        cin>>a;
        q2.push(a);
    }
    priority_queue<int> ans;
    while(q1.size()>0 && q2.size()>0)
    {
        int e1=q1.top();
        int e2=q2.top();
        if(e1>=e2)
        {
            ans.push(e1);
            q1.pop();
        }
        else{
            ans.push(e2);
            q2.pop();
        }
    }
    while(q1.size()>0)
    {
        ans.push(q1.top());
        q1.pop();
    }
    while(q2.size()>0)
    {
        ans.push(q2.top());
        q2.pop();
    }
    while(ans.size()>0)
    {
        cout<<ans.top()<<" ";
        ans.pop();
    }
    return 0;
}