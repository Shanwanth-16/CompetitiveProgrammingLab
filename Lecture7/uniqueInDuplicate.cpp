#include <iostream>
using namespace std;
int binSearch(vector<int> arr,int l,int r)
{
    int mid;
    while(l<=r)
    {
        mid=(l+r)/2;
        if(arr[mid]!=arr[mid-1] && arr[mid]!=arr[mid+1])
        {
            return mid;
        }
        if((r-l)/2 % 2==0)
        {
            if(arr[mid]==arr[mid-1] && mid>l)
            {
                r=mid-1;
            }
            else if(arr[mid]==arr[mid+1] && mid<r){
                l=mid+1;
            }
        }
        else{
            if(arr[mid]==arr[mid-1] && mid>l)
            {
                l=mid+1;
            }
            else if(arr[mid]==arr[mid+1] && mid<r)
            {
                r=mid-1;
            }
        }
    }
    return -1;
}
int main()
{
    cout<<"Enter the size:";
    int size;
    cin>>size;
    vector<int> arr(size);
    cout<<"enter the elements of the array"<<endl;
    for(int i=0;i<size;i++)
    {
        cin>>arr[i];
    }
    int ans=binSearch(arr,0,size-1);
    if(ans==-1)
    {
        cout<<"no unique element"<<endl;
    }
    else{
        cout<<"unique element:"<<arr[ans]<<" at "<<ans<<endl;
    }
    return 0;
}