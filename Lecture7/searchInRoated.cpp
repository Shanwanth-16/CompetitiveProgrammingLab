#include <iostream>
using namespace std;
int BinSearch(vector<int> arr,int l,int r)
{
    cout<<l<<" "<<r<<endl;
    if(l>r)
    {
        return -1;
    }   
    int mid=(l+r)/2;
    cout<<mid<<endl;
    if(arr[mid]<arr[mid-1] && arr[mid]<arr[mid+1])
    {
        return mid;
    }
    else if(arr[mid]>arr[l] && arr[mid]>arr[r])
    {
        return BinSearch(arr,mid+1,r);
    }
    else if(arr[mid]<arr[l] && arr[mid]<arr[r])
    {
        return BinSearch(arr,l,mid-1);
    }
}
int Search(vector<int> arr,int l,int r,int target)
{
    cout<<l<<" "<<r<<endl;
    if(l>r)
    {
        return -1;
    }
    int mid=l+(r-l)/2; //mid=low+(high-low)/2;
    cout<<mid<<endl;
    if(arr[mid]==target)
    {
        return mid;
    }
    else if(arr[mid]>target){
        return Search(arr,l,mid-1,target);
    }
    else if(arr[mid]<target)
    {
        return Search(arr,mid+1,r,target);
    }
}
int main()
{
    cout<<"Enter the size:";
    int size;
    cin>>size;
    vector<int> arr(size);
    cout<<"Enter the elements of the array"<<endl;
    for(int i=0;i<size;i++)
    {
        cin>>arr[i];
    }
    int n=arr.size();
    int smallest;
    if(arr[n-1]<arr[0]){
        //1)find the index of smallest element in array and 2)find the index of any val in the array
        smallest=BinSearch(arr,0,arr.size()-1);
    }
    else{
        smallest=0;
    }
    cout<<"ans:";
    cout<<smallest<<endl;
   
    //as i get the smallest element now i can compare last element of array to find if the element

    cout<<"Enter the element you want to search in the arrray:";//assume given arr id rotated sorted
    int num;
    cin>>num;
    int ans;
    if(num>arr[n-1])
    {
        ans=Search(arr,0,smallest-1,num);
    }
    else{
        ans=Search(arr,smallest,n-1,num);
    }
    cout<<"elements index:"<<ans<<endl;
    return 0;
}