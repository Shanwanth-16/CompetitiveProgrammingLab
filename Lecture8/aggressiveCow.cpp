#include <iostream>
using namespace std;
class Solution {
  public:
    static bool comp(int a, int b) {
        // Your comparison logic
        return a < b;  // Example
    }
    bool check(vector<int> arr,int minDist,int k)
    {
        for(int i=0;i<arr.size();i++)
        {
            cout<<arr[i]<<" ";
            
        }
        cout<<" "<<endl;
        int lastCowPos=arr[0];
        k--;
        for(int i=1;i<arr.size();i++)
        {
            if(arr[i]-lastCowPos>=minDist && k>0)
            {
                k--;
                lastCowPos=arr[i];
            }
        }
        cout<<k<<endl;
        if(k==0)
        {
            return true;
        }
        return false;
    }
    int aggressiveCows(vector<int> &stalls, int k) {
        sort(stalls.begin(),stalls.end(),comp);
        int n=stalls.size();
        int min=stalls[0];
        int max=stalls[n-1];
        //range of possible ans will be from 1 to max-min
        int l=1;
        int r=max-min;
        int mid;
        int ans=0;
        while(l<=r)
        {
            mid=(l+r)/2;
            cout<<l<<" "<<r<<endl;
            cout<<mid<<endl;
            cout<<check(stalls,mid,k)<<endl;
            if(check(stalls,mid,k))
            {
                if(mid>ans)
                {
                    ans=mid;
                }
                l=mid+1;
            }
            else
            {
                r=mid-1;
            }
        }
        return ans;
    }
};

int main()
{
    cout<<"Enter the size:";
    int size;
    cin>>size;
    vector<int> arr(size);
    for(int i=0;i<size;i++)
    {
        cin>>arr[i];
    }
    cout<<"Enter the number of cows";
    int k;
    cin>>k;
    Solution obj;
    int ans=obj.aggressiveCows(arr,k);
    cout<<"ans:"<<ans<<endl;
}