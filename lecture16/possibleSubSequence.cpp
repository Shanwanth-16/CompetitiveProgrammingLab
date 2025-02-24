#include <iostream>
using namespace std;
void recurse(string curr,vector<string> &ans,string input,int index)
{
    if(index==input.length())
    {
        ans.push_back(curr);
    }
    else{
        recurse(curr+input[index],ans,input,index+1);
        recurse(curr,ans,input,index+1);
    }
    
}
int main()
{
    cout<<"Enter the string to get all the substrings"<<endl;
    string input;
    cin>>input;
    vector<string> ans;
    recurse("",ans,input,0);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
}