#include <iostream>
using namespace std;

int main() {
    int size;
    cout<<"Enter the size of array"<<endl;
    cin>>size;
    int arr[size];
    for(int i=0;i<size;i++)
    {
        cin>>arr[i];
    }
    sort(arr,arr+size);
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<endl;
    }
    return 0;
}
