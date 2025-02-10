#include <iostream>
using namespace std;
int binSearchForFirstOccurence(vector<int> nums,int l,int r,int target)
{
    int mid;
    
    while(l<r)
    {
        cout<<l<<" "<<r<<endl;
        cout<<mid<<endl;
        mid=(l+r)/2;
        if(nums[mid]<target)
        {
            l=mid+1;
        }
        else
        {
            r=mid;
        }
    }
    return l;
}
int binSearchForLastOccurence(vector<int> nums,int l,int r,int target)
{
    int mid;
    while(l<r)
    {
        mid=(l+r)/2;
        cout<<l<<" "<<r<<endl;
        cout<<mid<<endl;
        if(nums[mid]>target)
        {
            r=mid;
        }
        else
        {
            l=mid+1;
        }
    }
    return l;
}
int main()
{
    int size;
    cout<<"Enter the size:";
    cin>>size;
    vector<int> nums(size);
    for(int i=0;i<size;i++)
    {
        cin>>nums[i]; //the array will  be sorted
    }
    cout<<"Enter the number you want to find the first and last occurence:";
    int a;
    cin>>a;
    int f=binSearchForFirstOccurence(nums,0,size-1,a);
    cout<<"second func"<<endl;
    int l=binSearchForLastOccurence(nums,0,size-1,a);
    cout<<"ans:"<<f<<"   "<<l<<endl;
}