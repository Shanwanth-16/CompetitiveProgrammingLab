#include <iostream>
using namespace std;
int main() {
    int arr[10]={1,1,2,2,3,4,4,5,6,6};
    int x=arr[0];
    for(int i=1;i<10;i++)
    {
        x^=arr[i];
    }
    int a=0;
    int b=0;
    int rightSetBit=x&~(x-1);
    for(int i=0;i<10;i++)
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
    cout<<a<<endl;
    cout<<b<<endl;
    return 0;
}