#include <iostream>
#include <queue>
using namespace std;
void BFS(vector<vector<int> > &graph,vector<bool> visited,int start)
{
    queue<int> q;
    q.push(start);
    visited[start]=true;
    while(!q.empty())
    {
        int t=q.front();
        q.pop();
        cout<<t<<endl;
        for(int i=0;i<graph[t].size();i++)
        {
            if(graph[t][i]!=0 && visited[i]==false)
            {
                q.push(i);
                visited[i]=true;
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
    int start;
    cin>>start;
    vector<bool> visited(n);
    BFS(graph,visited,start);
    return 0;
}