#include <iostream>
#include <vector>
using namespace std;
class Solution {
    public:
      // Function to find the maximum number of meetings that can
      // be performed in a meeting room.
      class group{
          public: 
          int s;
          int e;
      };
      static bool groupByEnd(group g1,group g2)
      {
          return g1.e<g2.e;
      }
      int maxMeetings(vector<int>& start, vector<int>& end) {
          // Your code here
          vector<group> arr;
          for(int i=0;i<start.size();i++)
          {
              group temp;
              temp.s=start[i];
              temp.e=end[i];
              arr.push_back(temp);
          }
          sort(arr.begin(),arr.end(),groupByEnd);
          int last=-1;
          int ans=0;
          for(int i=0;i<arr.size();i++)
          {
              if(arr[i].s>last)
              {
                  ans++;
                  last=arr[i].e;
              }
          }
          return ans;
      }
  };

  int main()
  {
    Solution obj;
    vector<int> start;
    vector<int> end;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n;
    cin>>n;
    while(n--)
    {
        int k;
        cin>>k;
        start.resize(k);
        end.resize(k);
        for(int i=0;i<k;i++)
        {
            cin>>start[i];
        }
        for(int i=0;i<k;i++)
        {
            cin>>end[i];
        }
        int ans=obj.maxMeetings(start,end);
        cout<<ans<<endl;
    }
    
  }