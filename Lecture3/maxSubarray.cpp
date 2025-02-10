#include <iostream>
using namespace std;

int main()
{
    cout<<"Enter the size of array"<<endl;
    int size;
    cin>>size;
    cout<<"Enter the size of subarray"<<endl;
    int k;
    cin>>k;
    int arr[size];
    for(int i=0;i<size;i++)
    {
        cin>>arr[i];
    }

    int max=0;//should take negative infinity
    int sum=0;
    for(int i=0;i<k;i++)
    {
        sum+=arr[i];
    }
    max=sum;
    for(int i=k;i<size;i++)
    {
        sum+=arr[i];
        sum-=arr[i-k];
        if(sum>max)
        {
            max=sum;
        }
    }
    cout<<sum<<" is the max value of subarr of size "<<k<<endl;
    return 0;
}