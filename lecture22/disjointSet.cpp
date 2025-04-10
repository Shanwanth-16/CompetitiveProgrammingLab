#include <iostream>
using namespace std;
class UnionFind{
      private:
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
int main()
{
      UnionFind obj(10);
      cout<<obj.Find(8)<<endl;
      obj.Union(8,9);
      cout<<obj.Find(8)<<endl;
      cout<<obj.Find(9)<<endl;
}