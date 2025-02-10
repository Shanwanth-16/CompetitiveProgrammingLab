#include <iostream>
#include <stack>
using namespace std;

int main()
{
    int size;
    cout<<"Enter the size:";
    cin>>size;
    int arr[size];
    int ans[size];
    for(int i=0;i<size;i++)
    {
        cin>>arr[i];
        ans[i]=1;
    }
    stack<int> s;
    for(int i=0;i<size;i++)
    {
        if(s.empty() || arr[s.top()]>arr[i])
        {
            s.push(i);
        }
        else{
            while(!s.empty() && arr[s.top()]<arr[i])
            {
                ans[i]+=ans[s.top()];
                s.pop();
            }
            s.push(i);
        }
    }
    for(int i=0;i<size;i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}