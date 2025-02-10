#include <iostream>
using namespace std;
//here we have to find the sum of elements between a given range of indices
int main()
{
    cout<<"Enter the size of the array"<<endl;
    int size;
    cin>>size;
    int arr[size];
    for(int i=0;i<size;i++)
    {
        cin>>arr[i];
    }
    cout<<"Enter the number of queries to enter"<<endl;
    int n;
    cin>>n;
    int query[n][2];
    for(int i=0;i<n;i++)
    {
        cout<<"Enter the query values"<<endl;
        cin>>query[i][0];
        cin>>query[i][1];
    }
    int prefixSum[size];
    int sum=0;
    for(int i=0;i<size;i++)
    {
        if(arr[i]%2!=0)
        {
            sum+=arr[i];
        }
        prefixSum[i]=sum;
    }
    //prrocessing the queries
    int ans[n];
    for(int i=0;i<n;i++)
    {
        int l=query[i][0];
        int r=query[i][1];
        int a;
        if(arr[i]%2==0)
        {
            a=prefixSum[r]-prefixSum[l];
        }
        else
        {
            a=prefixSum[r]-prefixSum[l]+arr[l];
        }
        ans[i]=a;
    }
    for(int i=0;i<n;i++)
    {
        cout<<"sum of elements between "<<query[i][0]<<" and "<<query[i][1]<<" is "<<ans[i]<<endl;
    }
    return 0;
}