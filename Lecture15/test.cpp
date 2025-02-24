#include <iostream>
using namespace std;
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n;
    cin>>n;
    while(n--)
    {
        int len;
        cin>>len;
        vector<int> arr(len);
        for(int i=0;i<len;i++)
        {
            cin>>arr[i];
        }
        for(int i=0;i<len;i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}

