#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    cout<<"Enter the size of the array"<<endl;
    int size;
    cin>>size;
    vector<int> arr(size);
    for(int i=0;i<size;i++)
    {
        cin>>arr[i];
    }
    cout<<"Enter the val of k:";
    int k;
    cin>>k;
    priority_queue<int , vector<int>,greater<int> > min_heap;
    for(int i=0;i<=k;i++)
    {
        min_heap.push(arr[i]);
    }
    int ans[size];
    for(int i=k+1;i<size;i++)
    {
        ans[i-k-1]=min_heap.top();
        min_heap.pop();
        min_heap.push(arr[i]);
    }
    for(int i=size-k-1;i<size;i++)
    {
        ans[i]=min_heap.top();
        min_heap.pop();
    }for(int i=0;i<size;i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}

