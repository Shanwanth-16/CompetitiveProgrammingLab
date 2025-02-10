#include <iostream>
using namespace std;
int binary(int low,int high,int num,int n)
{
    int mid;
    while(low<=high)
    {
        mid=(low+high)/2;
        int k=1;
        for(int i=0;i<n;i++)
        {
            k*=mid;
        }
        if(k==num)
        {
            return mid;
        }
        else if(k>num)
        {
             high=mid-1;
            
        }
        else{
           low=mid+1;
        }
    }
    return -1;
}
int main()
{
    cout<<"Enter the number ans val of n"<<endl;
    int num,n;
    cin>>num>>n; // nth root of num=?
    int ans=binary(1,num/n,num,n);
    cout<<ans<<endl;
}