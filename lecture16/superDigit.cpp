#include <iostream>
using namespace std;
int recurse(int num)
{
    if(num/10==0)
    {
        return num;
    }
    int newnum=0;
    while(num>0)
    {
        newnum+=num%10;
        num=num/10;
    }
    return recurse(newnum);
}
int main()
{
    cout<<"Enter the number"<<endl;
    int num;
    cin>>num;
    int ans=recurse(num);
    cout<<ans<<endl;
}