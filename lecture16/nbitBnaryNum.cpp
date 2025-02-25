#include <iostream>
#include <vector>
using namespace std;
class Solution{
    public:	
        bool check(string s)
        {
            int n1=0;
            int n0=0;
            for(int i=0;i<s.length();i++)
            {
                if(s[i]=='1')
                {
                    n1++;
                }
                else
                {
                    n0++;
                }
            }
            if(n1>=n0)
            {
                return true;
            }
            return false;
        }
        void recurse(string curr,int i,int n,vector<string> &ans)
        {
            if(i>=n)
            {
                ans.push_back(curr);
            }
            else
            {
                string temp1=curr+"1";
                string temp2=curr+"0";
                if(check(temp1))
                {
                    recurse(temp1,i+1,n,ans);
                }
                if(check(temp2))
                {
                    recurse(temp2,i+1,n,ans);
                }
            }
            
        }
        vector<string> NBitBinary(int n)
        {
            // Your code goes here
            vector<string> ans;
            recurse("",0,n,ans);
            return ans;
        }
    };

int main()
{
    Solution obj;
    vector<string> ans=obj.NBitBinary(9);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" "<<endl;
    }
    return 0;
}

