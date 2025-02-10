#include <iostream>
using namespace std;
int main()
{
    cout<<"Enter the size of the array:";
    int size;
    cin>>size;
    vector<int> arr(size);
    cout<<"Enter the position in the array";
    int pos;
    cin>>pos;
    cout<<"ENter the elements of the array"<<endl;
    for(int i=0;i<size;i++)
    {
        cin>>arr[i];
    }
    int l=0;
    int r=size-1;
    int mid;
    pos=pos-arr[l]+1;
    while(l<r)
    {
        mid=(l+r)/2;
        cout<<l<<" "<<r<<endl;
        int missing=(arr[mid]-arr[l])-(mid-l);
        if(l==mid)
        {
            r--;
        }
        else{
            if(missing<pos)
            {
                pos-=missing;
                l=mid;
            }
            else{
                r=mid-1;
            }
        }
        
    }
    cout<<"l:"<<l<<endl;
    cout<<"ans:"<<arr[l]+pos<<endl;
    return 0;
}