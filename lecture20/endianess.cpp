#include <iostream>
using namespace std;
int main()
{
    short num=12;
    char *byte=(char *)&num;
    cout<<&num<<endl;
    if(*byte==12)
    {
        cout<<"Little endian "<<byte<<endl;
    }
    else{
        cout<<"Big endian "<<byte<<endl;
    }
    return 0;
}