#include <iostream>
using namespace std;


bool CycleDetection(vector<vector<int> > graph,vector<bool> &visited,vector<bool> &stack)
{

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
    vector<bool> visited(n,false);
    vector<bool> stack(n,false);
    bool ans=CycleDetection(graph,visited,stack);
    cout<<ans<<endl;
    return 0;
}