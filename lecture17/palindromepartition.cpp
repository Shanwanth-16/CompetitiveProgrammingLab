#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
    public:
        bool isPalindrome(string s,int l,int r)
        {
            while(l<r)
            {
                if(s[l]!=s[r])
                {
                    return false;
                }
                l=l+1;
                r=r-1;
            }
            return true;
        }
        void dfs(string s,vector<string> &curr,vector<vector<string> > &ans,int index)
        {
            if(index==s.length())
            {
                ans.push_back(curr);
                return;
            }
            for(int i=index;i<s.size();i++)
            {
                if(isPalindrome(s,index,i))
                {
                    curr.push_back(s.substr(index,(i-index+1)));
                    dfs(s,curr,ans,i+1);
                    curr.pop_back();
                }
            }
        }
        vector<vector<string> > partition(string s) {
            vector<vector<string> > ans;
            vector<string> curr;
            dfs(s,curr,ans,0);
            return ans;
        }
    };
int main() {
   Solution obj;
   vector<vector<string> > ans=obj.partition("ababba");
   for(int i=0;i<ans.size();i++)
   {
     for(int j=0;j<ans[i].size();j++)
     {
        cout<<ans[i][j]<<"  ";
     }
     cout<<""<<endl;
   }
    return 0;
}
