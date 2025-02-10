#include <iostream>
#include <stack>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the number of people:";
    cin>>n;
    int arr[n][n];
    for(int i=0;i<n;i++)
    {
        cout<<"Enter 0 if"<<i<<"do not know else enter 1"<<endl;
        for(int j=0;j<n;j++)
        {
            if(i==j)
            {
                arr[i][j]=0;
                continue;
            }
            cout<<i<<" and "<<j<<endl;
            cin>>arr[i][j];
        }
    }
    stack<int> s;
    for(int i=0;i<n;i++)
    {
        s.push(i);
    }
    while(s.size()>1)
    {
        int a=s.top();
        s.pop();
        int b=s.top();
        s.pop();
        if(arr[a][b]==1 && arr[b][a]==0)
        {
            s.push(b);
        }
        else if(arr[b][a]==1 && arr[a][b]==0)
        {
            s.push(a);
        }
        else if((arr[a][b]==0 && arr[b][a]==0 ) || (arr[a][b]==1 && arr[b][a]==1))
        {
            continue;
        }
    }
    int p=s.top();
    int row=0;
    int col=0;
    for(int i=0;i<n;i++)
    {
        row+=arr[p][i];
        col+=arr[i][p];
    }
    if(row==0 && col==n-1)
    {
        cout<<p<<"is the celebrity"<<endl;
    }
    else{
        cout<<"No celebrity found";
    }
    return 0;
}