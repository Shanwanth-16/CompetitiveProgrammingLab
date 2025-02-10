#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int size;
    cout<<"Enter the size:";
    cin>>size;
    vector<int> arr(size);
    cout<<"Enter the elements in tree order";
    for(int i=0;i<size;i++)
    {
        cin>>arr[i];
    }
    for(int i=0;i<size/2;i++)
    {
        int l=i*2+1;
        int r=i*2+2;
        if(arr[i]<arr[l] || arr[i]<arr[r])
        {
            cout<<"Not a max heap"<<endl;
            return 0;
        }
    }
    cout<<"it is a max heap"<<endl;
    return 0;
}