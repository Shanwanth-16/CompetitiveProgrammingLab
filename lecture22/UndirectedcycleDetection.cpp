#include <iostream>
using namespace std;
class UnionFind{
      public:
            vector<int> arr;
      public:
            UnionFind(int s)
            {
                  arr.resize(s);
                  for(int i=0;i<s;i++)
                  {
                        arr[i]=i;
                  }
            }
            int Find(int a)
            {
                  if(arr[a]==a)
                  {
                        return a;
                  }
                  return Find(arr[a]);
            }
            void Union(int a,int b)
            {
                  int a1=Find(a);
                  int b1=Find(b);
                  arr[a1]=b1;
            }
};
bool CycleDetection(vector<vector<int> > graph)
{
      int n=graph.size();
      UnionFind arr(n);
      for(int i=0;i<n;i++)
      {
            for(int j=i;j<n;j++)
            {
                  if(graph[i][j]!=0)
                  {
                        if(arr.Find(i)!=arr.Find(j))
                        {
                              arr.Union(j,i);
                        }
                        else{
                              for(int i=0;i<n;i++)
                              {
                                    cout<<arr.arr[i]<<endl;
                              }
                              return true;
                        }
                  }
            }
      }
      return false;
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
    bool ans=CycleDetection(graph);
    cout<<ans<<endl;
    return 0;
}