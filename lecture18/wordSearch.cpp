#include <iostream>
#include <vector>
using namespace std;
class Solution {
    public:
        bool backtrack(vector<vector<char> >& board, string word,int x,int y,vector<vector<int> > &visited,int currIndex)
        {
            if(currIndex==word.length())
            {
                return true;
            }
            int n=board.size();
            int m=board[0].size();
            if(x<0 || y<0 || y>=m || x>=n || board[x][y]!=word[currIndex] || visited[x][y]!=-1)
            {
                return false;
            }
            visited[x][y]=1;
            bool res=backtrack(board,word,x+1,y,visited,currIndex+1) || 
                    backtrack(board,word,x-1,y,visited,currIndex+1) || 
                    backtrack(board,word,x,y+1,visited,currIndex+1) || 
                    backtrack(board,word,x,y-1,visited,currIndex+1);
            visited[x][y]=-1;
            return res;
        }
        bool exist(vector<vector<char> >& board, string word) {
            int n=board.size();
            int m=board[0].size();
            vector<vector<int> > visited(n,vector<int>(m,-1));
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<m;j++)
                {
                    if(backtrack(board,word,i,j,visited,0))
                    {
                        return true;
                    }
                }
            }
            return false;
        }
    };

int main()
{
    Solution obj;
    vector<vector<char> > board; 
    string word;
    bool ans=obj.exist(board,word);
    cout<<ans<<endl;
    return 0;
}