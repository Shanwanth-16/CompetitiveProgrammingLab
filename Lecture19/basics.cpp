#include <iostream>
#include <cassert>
using namespace std;
int set(int num,int pos)
{
    return num | (1<<pos);
}
int clear(int num,int pos)
{
    return num & (1>>pos);
}
int toggle(int num,int pos)
{
    return num^(1<<pos);
}
int main()
{
    int a=12;
    int b=12>>2;
    int c=12<<2;
    int d=set(12,4);
    return 0;
}