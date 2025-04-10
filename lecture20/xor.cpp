#include <iostream>
using namespace std;
int main() {
    int a=2;
    int b=6;
    int x=a^b;
    int y=(a&~b)|(~a&b);
    cout<<x<<" "<<y<<endl;
    return 0;
}