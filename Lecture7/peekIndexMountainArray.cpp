#include <iostream>
using namespace std;
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int l=0;
        int r=arr.size();
        int mid=0;
        while(l<=r)
        {
            mid=(l+r)/2;
            if(mid>0 && mid<arr.size() && arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1])
            {
                return mid;
            }
            else if(mid<arr.size() && arr[mid]<arr[mid+1])
            {
                l=mid+1;
            }
            else if(mid>0 && arr[mid]<arr[mid-1])
            {
                r=mid-1;
            }
        }
        return 0;
    }
};

int main()
{
    cout<<"Enter the size:";
    int size;
    cin>>size;
    vector<int> arr(size);
    for(int i=0;i<size;i++)
    {
        cin>>arr[i];
    }
    Solution obj;
    int ans=obj.peakIndexInMountainArray(arr);
    cout<<ans<<"is the index of peak element of the mountain array"<<endl;
    return 0;
}