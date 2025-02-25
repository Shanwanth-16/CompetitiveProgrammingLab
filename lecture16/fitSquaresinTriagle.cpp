#include <iostream>
#include <vector>
using namespace std;
int recurse(int base,int side)
{
    if(base<side)
    {
        return 0;
    }
    int curr=base/side -1;
    base=curr;
    return curr+recurse(base,side);
}
int main()
{
    cout<<"Enter the base of triangle and sidee of square"<<endl;
    int base;
    int side;
    cin>>base>>side;
    int ans=recurse(base,side);
    cout<<ans<<endl;
    return 0;
}