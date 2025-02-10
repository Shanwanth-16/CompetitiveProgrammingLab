//i have to give min of max amount of pages i can give to a student 
#include <iostream>
using namespace std;
bool check(vector<int> arr,int max,int k)
{
    int count=1;
    int sum=0;
    for(int i=0;i<arr.size();i++)
    {
        if(sum+arr[i]>max)
        {
            ++count;
            sum=arr[i];
        }
        else{
            sum+=arr[i];
        }
    }
    return (count<=k);
}
int main()
{
    int size;
    cout<<"Enter the size of the array";
    cin>>size;
    vector<int> arr(size);
    cout<<"Enter the elements of the array"<<endl;
    for(int i=0;i<size;i++)
    {
        cin>>arr[i];
    }
    cout<<"Enter the number of students:";
    int k;
    cin>>k;
    if(k>arr.size())
    return -1;
    
    int r=arr[0];
    int l=arr[0];
    for(int i=1;i<arr.size();i++)
    {
        if(l>arr[i])
        {
            l=arr[i];
        }
        r+=arr[i];
    }
    int mid=0;
    int ans=-1;
    
    while(l<=r)
    {
        mid=(l+r)/2;
        cout<<l<<" "<<r<<endl;
        cout<<mid<<endl;
        if(check(arr,mid,k))
        {
            ans=mid;
            r=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    cout<<"ans:"<<ans<<endl;
} 