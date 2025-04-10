#include <iostream>
using namespace std;
void DFS(vector<vector<int> > graph,vector<bool> &visited,int curr)
{
    visited[curr]=true;
    cout<<curr<<endl;
    for(int i=0;i<graph[curr].size();i++)
    {
        if(graph[curr][i]!=0 && visited[i]==false)
        {
            DFS(graph,visited,i);
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
    int start;
    cin>>start;
    vector<bool> visited(n);
    DFS(graph,visited,start);
    return 0;
}