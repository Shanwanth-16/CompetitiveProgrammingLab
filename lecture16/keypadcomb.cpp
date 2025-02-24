#include <iostream>
#include <vector>
#include <map>
using namespace std;
vector<string> recurse(map<int,vector<string> > m,int num,vector<string> ans)
{
    if(num==0)
    {
        return ans;
    }
    int temp=num%10;
    num=num/10;
    if(ans.size()==0)
    {
        for(int i=0;i<m[temp].size();i++)
        {
            ans.push_back(m[temp][i]);
        }
    }
    else{
        vector<string> newans;
        for(int i=0;i<ans.size();i++)
        {
            for(int j=0;j<m[temp].size();j++)
            {
                string temp1=ans[i]+m[temp][j];
                newans.push_back(temp1);
            }
        }
        ans=newans;
    }
    return recurse(m,num,ans);
    
}
int main()
{
    cout<<"Enter the keypad number"<<endl;
    int num;
    cin>>num;
    vector<string> ans;
    map<int,vector<string> > m;
    m[2].push_back("a");
    m[2].push_back("b");
    m[2].push_back("c");
    
    m[3].push_back("d");
    m[3].push_back("e");
    m[3].push_back("f");

    m[4].push_back("g");
    m[4].push_back("h");
    m[4].push_back("i");

    m[5].push_back("j");
    m[5].push_back("k");
    m[5].push_back("l");

    m[6].push_back("m");
    m[6].push_back("n");
    m[6].push_back("o");

    m[7].push_back("p");
    m[7].push_back("q");
    m[7].push_back("r");
    m[7].push_back("s");

    m[8].push_back("t");
    m[8].push_back("u");
    m[8].push_back("v");

    m[9].push_back("w");
    m[9].push_back("x");
    m[9].push_back("y");
    m[9].push_back("z");
    vector<string> finalans=recurse(m,num,ans);
    cout<<finalans.size()<<endl;
    for(int i=0;i<finalans.size();i++)
    {
        cout<<finalans[i]<<" ";
    }
    return 0;
}