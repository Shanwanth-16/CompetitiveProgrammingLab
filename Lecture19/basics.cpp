#include <iostream>
#include <cassert>
using namespace std;
int set(int num,int pos)
{
    return num | (1<<pos);
}
int clear(int num,int pos)
{
    return num & ~(1<<pos);
}
int toggle(int num,int pos)
{
    return num^(1<<pos);
}
int main()
{
    int a=7;
    int b=12>>2;
    int c=12<<2;
    int d=clear(24,3);
    cout<<d<<endl;
    cout<<(a|a+1)<<endl;
    cout<<(3^5)<<endl;
    return 0;
}