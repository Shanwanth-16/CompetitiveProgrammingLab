#include <iostream>
#include <vector>
using namespace std;
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n;
    cin>>n;
    vector<bitset<30> > workers(n);
    for(int i=0;i<n;i++)
    {
        for(int j=1;j<=30;j++)
        {
            int s;
            cin>>s;
            workers[i][j-1]=s;
        }
    }
    int max=0;
    int worker1=0;
    int worker2=0;
    int common;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            common=(workers[i] & workers[j]).count();
            if(common>max)
            {
                max=common;
                worker1=i;
                worker2=j;
            }
        }
    }
    cout<<common<<" days between workers "<<worker1<<" and "<<worker2<<endl;
    return 0;
}