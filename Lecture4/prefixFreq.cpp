#include <iostream>
using namespace std;
int main()
{
    cout<<"Enter the size of the array"<<endl;
    int size;
    cin>>size;
    int arr[size];
    cout<<"Enter the elements of the array in sequence"<<endl;
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
    int num;
    cout<<"Enter the num you want to find the freq"<<endl;
    cin>>num;
    int freq[size];
    int f=0;
    for(int i=0;i<size;i++)
    {
        if(arr[i]==num)
        {
            f++;
        }
        freq[i]=f;
    }
    int ans[n];
    for(int i=0;i<n;i++)
    {
        int l=query[i][0];
        int r=query[i][1];
        if(arr[l]==num)
        {
            ans[i]=freq[r]-freq[l]+1;
        }
        else{
            ans[i]=freq[r]-freq[l];
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<"number of occurences between "<<query[i][0]<<" and "<<query[i][1]<<" of "<< num <<" is "<<ans[i]<<endl;
    }
    return 0;
}