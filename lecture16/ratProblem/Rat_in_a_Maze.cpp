#include <iostream>
#include <vector>
#include <set>
using namespace std;
class Solution {
    public:
      bool check(vector<int> curr,set<vector<int> > &visited)
      {
          for(auto& path:visited)
          {
              if(path[0]==curr[0] && path[1]==curr[1])
              {
                  return false;
              }
          }
          return true;
      }
      vector<vector<int> > getPath(vector<int> curr,int n)
      {
          vector<vector<int> > ans;
          if(curr[1]-1>=0)
          {
              vector<int> temp;
              temp.push_back(curr[0]);
              temp.push_back(curr[1]-1);
              ans.push_back(temp);
          }
          if(curr[0]-1>=0)
          {
              vector<int> temp;
              temp.push_back(curr[0]-1);
              temp.push_back(curr[1]);
              ans.push_back(temp);
          }
          if(curr[0]+1<n)
          {
              vector<int> temp;
              temp.push_back(curr[0]+1);
              temp.push_back(curr[1]);
              ans.push_back(temp);
          }
          if(curr[1]+1<n)
          {
              vector<int> temp;
              temp.push_back(curr[0]);
              temp.push_back(curr[1]+1);
              ans.push_back(temp);
          }
          return ans;
      }
      string getDirection(vector<int> curr,vector<int> next)
      {
            string ans;
          if(next[0]>curr[0])
          {
              ans="D";
          }
          if(next[1]<curr[1])
          {
            ans= "L";
          }
          if(next[1]>curr[1])
          {
            ans= "R";
          }
          if(next[0]<curr[0])
          {
              ans="U";
          }
          return ans;
      }
      void backtrack(vector<vector<int> > &mat,set<vector<int> > &visited,vector<int> goal,vector<int> curr,vector<string> &ans,string currans)
      {
          if(curr[0]==goal[0] && curr[1]==goal[1])
          {
              ans.push_back(currans);
          }
          else
          {
              visited.insert(curr);
              vector<vector<int> > nextPossiblePath=getPath(curr,mat.size());
              for(auto& path:nextPossiblePath)
              {
                  if(mat[path[0]][path[1]]==1 && check(path,visited))
                  {
                      string direction=getDirection(curr,path);
                      backtrack(mat,visited,goal,path,ans,currans+direction);
                  }
              }
              visited.erase(curr);
          }
      }
      vector<string> findPath(vector<vector<int> > &mat) {
          // code here
          int n=mat.size();
          vector<string> ans;
          set<vector<int> > visited;
          vector<int> goal;
          vector<int> curr;
          goal.push_back(n-1);
          goal.push_back(n-1);
          curr.push_back(0);
          curr.push_back(0);
          backtrack(mat,visited,goal,curr,ans,"");
          return ans;
      }
  };

  int main()
  {
        Solution obj;
        vector<vector<int> > mat;
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
        int n;
        cin>>n;
        for (int j = 0; j < n; j++) {
        {
            vector<int> temp;
            for(int i=0;i<n;i++)
            {
                int p;
                cin>>p;
                temp.push_back(p);
            }
            mat.push_back(temp);
        }
    }
        vector<string> ans= obj.findPath(mat);
        cout<<ans.size()<<endl;
        for(int i=0;i<ans.size();i++)
        {
            cout<<ans[i]<<"   ";
        }
        return 0;
}