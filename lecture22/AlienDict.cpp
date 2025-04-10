#include <iostream>
using namespace std;
#include <map>
#include <set>
class Solution {
      public:
          bool dfs(char curr,map<char,set<char> > adj,map<char,bool> &visited,vector<char> &ans)
          {
              if(visited.find(curr)!=visited.end())
              {
                  return visited[curr];
              }
              visited[curr]=true;
              for(auto nei:adj[curr])
              {
                  if(dfs(nei,adj,visited,ans))
                  {
                      return true;
                  }
              }
              ans.push_back(curr);
              visited[curr]=false;
              return false;
          }
          string foreignDictionary(vector<string>& words) {
              //given the list of words find the correct alphabetical order of aliens
              map<char,set<char> > adj;
              for(int i=0;i<words.size();i++)
              {
                  int n=words[i].length();
                  for(int j=0;j<n;j++)
                  {
                      set<char> temp;
                      adj[words[i][j]]=temp;
                  }
              }
              for(int i=0;i<words.size()-1;i++)
              {
                  string s1=words[i];
                  string s2=words[i+1];
                  int minLen=min(s1.length(),s2.length());
                  if(s1.length()>s2.length() && s1.substr(0,minLen)==s2.substr(0,minLen))
                  {
                      return "";
                  }
                  for(int j=0;j<minLen;j++)
                  {
                      if(s1[j]!=s2[j])
                      {
                          set<char> temp = adj[s1[j]];
                          temp.insert(s2[j]);
                          adj[s1[j]] = temp;
                          break;
                      }
                      
                  }
              }
              map<char,bool> visited;
              vector<char> ans;
              for(auto &pair:adj)
              { 
                  if(dfs(pair.first,adj,visited,ans))
                  {
                      return "";
                  }
              }
              string concat="";
              for(int i=ans.size()-1;i>=0;i--)
              {
                  concat+=ans[i];
              }
              return concat;
          }
      };
int main()
{
    Solution obj;
    vector<string> p;
    p.push_back("wrt");
    p.push_back("wrf");
    p.push_back("er");
    p.push_back("ett");
    p.push_back("rftt");
    p.push_back("te");
    string ans=obj.foreignDictionary(p);
    cout<<ans<<endl;
    return 0;
}      