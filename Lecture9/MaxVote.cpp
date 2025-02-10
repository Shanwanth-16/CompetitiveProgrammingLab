#include <iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the population:";
    cin>>n;
    vector<int> votes(n);
    for(int i=0;i<n;i++)
    {
        cin>>votes[i];
    }
    sort(votes.begin(),votes.end());
    int winner=votes[0];
    int currCand=votes[0];
    int currCounter=1;
    int maxCounter=1;
    for(int i=1;i<votes.size();i++)
    {
        if(votes[i]==votes[i-1])
        {
            currCounter++;
        }
        else
        {
            currCand=votes[i];
            currCounter=1;
        }
        if(currCounter>maxCounter)
        {
            maxCounter=currCounter;
            winner=currCand;
        }
    }
    cout<<winner<<" is winner with "<<maxCounter<<" votes"<<endl;
}