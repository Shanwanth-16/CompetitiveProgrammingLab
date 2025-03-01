#include <iostream>
#include <vector>
using namespace std;
void backtrack(vector<int> arr,vector<int>& ans,int curr,int index)
{
    if(index==arr.size())
    {
        ans.push_back(curr);
        return;
    }
    backtrack(arr,ans,curr+arr[index],index+1);
    backtrack(arr,ans,curr,index+1);
}
int main()
{
    vector<int> arr;
    arr.push_back(1);
    arr.push_back(2);
    vector<int> ans;
    int curr=0;
    backtrack(arr,ans,curr,0);
    for(int i:ans)
    {
        cout<<i<<" ";
    }
    return 0;
}