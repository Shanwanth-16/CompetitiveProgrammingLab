#include <iostream>
using namespace std;
int main() {
    int arr[8]={1,2,2,3,4,4,5,6};
    int x=arr[0];
    for(int i=1;i<8;i++)
    {
        x^=arr[i];
    }
    for(int i=1;i<7;i++)
    {
        x^=i;
    }
    int a=0;
    int b=0;
    int rightSetBit=x&~(x-1);
    for(int i=0;i<8;i++)
    {
        if(arr[i] & rightSetBit)
        {
            a^=arr[i];
        }
        else
        {
            b^=arr[i];
        }
    }
    for(int i=1;i<7;i++)
    {
        if(i & rightSetBit)
        {
            a^=i;
        }
        else
        {
            b^=i;
        }
    }
    cout<<a<<endl;
    cout<<b<<endl;
    return 0;
}