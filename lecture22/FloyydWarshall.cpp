#include <iostream>
using namespace std;

void FloyydWarshall(vector<vector<int> > graph,vector<vector<int> > &A)
{
      int n=graph.size();
      for(int k=0;k<n;k++)
      {
            for(int i=0;i<n;i++)
            {
                  for(int j=0;j<n;j++)
                  {
                        if (A[i][k] != INT_MAX && A[k][j] != INT_MAX) {  // Avoid overflow with INT_MAX
                              A[i][j] = min(A[i][j], A[i][k] + A[k][j]);
                          }
                  }
            }
      }
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
    vector<vector<int> > A(n,vector<int>(n));
    for(int i=0;i<n;i++)
    {
      for(int j=0;j<n;j++)
      {

            if(graph[i][j]==0)
            {
                  A[i][j]=graph[i][j];
            }
            else
            {
                  A[i][j]=INT_MAX;
            }
      }
    }
    FloyydWarshall(graph,A);
    return 0;
}