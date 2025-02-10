//question given on whatsapp
#include <iostream>
using namespace std;
int main()
{
    cout<<"Enter the number of test cases"<<endl;
    int a;
    cin>>a;
    for(int i=0;i<a;i++)
    {
        int n;
        int k;
        cout<<"Enter the values of k,n"<<endl;
        cin>>n;
        cin>>k;
        int prefixSum[k];
        for(int j=0;j<k;j++)
        {
            cin>>prefixSum[j];
        }
        if((sizeof(prefixSum)/sizeof(prefixSum[0]))==1)
        {
            cout<<"yes"<<endl;
            continue;
        }
        int minVal=prefixSum[1]-prefixSum[0];
        if(minVal*(n-k+1) < prefixSum[0])
        {
            cout<<"No"<<endl;
        }
        else{
            cout<<"Yes"<<endl;
        }
    }
    return 0;
}