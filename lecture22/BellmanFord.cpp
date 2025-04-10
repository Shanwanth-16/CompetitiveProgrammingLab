#include <iostream>
using namespace std;
int Bellman_Ford(vector<vector<int> > graph,vector<int> &shortestDist,int start)
{
      shortestDist[start]=0;
      int n=graph.size();
      for(int i=0;i<n-1;i++)
      {
            for(int j=0;j<graph.size();j++)
            {
                  for(int k=0;k<graph.size();k++)
                  {
                        if(graph[j][k]!=0 && shortestDist[j]!=INT_MAX && shortestDist[k]>shortestDist[j]+graph[j][k])
                        {
                              shortestDist[k]=shortestDist[j]+graph[j][k];
                        }
                  }
            }
      }
      for(int j=0;j<graph.size();j++)
      {
            for(int k=0;k<graph.size();k++)
            {
                  if(graph[j][k]!=0 && shortestDist[j]!=INT_MAX && shortestDist[k]>shortestDist[j]+graph[j][k])
                  {
                        cout<<"Negative Cycle Detected"<<endl;
                        return -1; 
                  }
            }
      }
      return 1;
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n;
    cin >> n; // Read number of vertices
    vector<vector<int> > graph(n, vector<int>(n));

    // Read the 2D array (adjacency matrix) from the input file
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }
    int start;
    cin>>start;
    vector<int> shortestDist(n,INT_MAX);
    int a=Bellman_Ford(graph,shortestDist,start);
    if(a==1)
    {
      for(int i=0;i<n;i++)
      {
            cout<<shortestDist[i]<<endl;
      }
    }
    return 0;
}