#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int minKey(vector<int> &key, vector<bool> &mstSet) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < mstSet.size(); v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;
    return min_index;
}

void printMST(vector<int> &parent, vector<vector<int> > &graph) {
    cout << "Edge \tWeight\n";
    for (int i = 1; i < graph.size(); i++)
        cout << parent[i] << " - " << i << " \t" << graph[parent[i]][i] << " \n";
}

void primMST(vector<vector<int> > &graph) {
    int V = graph.size();
    vector<int> parent(V);
    vector<int> key(V);
    vector<bool> mstSet(V);

    for (int i = 0; i < V; i++)
        key[i] = INT_MAX, mstSet[i] = false;

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet);
        mstSet[u] = true;

        for (int v = 0; v < V; v++)
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }

    printMST(parent, graph);
}

int main() {
    
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
    
    primMST(graph); // Run Prim's algorithm

    return 0;
}
