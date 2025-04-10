#include <iostream>
using namespace std;
int main() {
    int arr[10]={1,1,1,2,2,2,3,3,3,4};
    int res=0;
    int mask,sum;
    for(int i=0;i<32;i++)
    {
      mask=(1<<i);
      sum=0;
      for(int n:arr)
      {
          if(mask & n)
          {
              sum++;
          }
      }
      if(sum%3==1)
       {
           res|=mask;
       } 
    }
    cout<<res<<endl;
    return 0;
}