#include <iostream>
#include <vector>
using namespace std;
class Solution {
    public:
      void backtrack(vector<int>& ans,int n,int start,int curr)
      {
          if(n<0)
          {
              ans.push_back(curr);
              return;
          }
          for(int i=start;i<=9;i++)
          {
              backtrack(ans,n-1,i+1,curr+(i*(pow(10,n))));
          }
      }
      vector<int> increasingNumbers(int n) {
          // Write Your Code here
          vector<int> ans;
          if(n==1)
          {
              ans.push_back(0);
          }
          backtrack(ans,n-1,1,0);
          return ans;
      }
  };
  int main()
  {
    Solution obj;
    vector<int> ans=obj.increasingNumbers(2);
    for(int i:ans)
    {
        cout<<i<<" ";
    }
    return 0;
  }