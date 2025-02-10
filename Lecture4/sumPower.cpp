#include <iostream>
#include <string>
using namespace std;
int  main()
{
    cout<<"Enter the the string"<<endl;
    string input;
    cin>>input;
    cout<<"Enter the size of the display"<<endl;
    int k;
    cin>>k;
    int ans;
    for(int i=1;i<input.length();i++)
    {
         if(input[i]!=input[i-1])
        {
            if(i<k)
            {
                ans+=i;
            }
            else
            {
                ans+=(k-1);
            }
        }
    }
    cout<<ans<<" is the number of changes we make in the whole process"<<endl;
}
