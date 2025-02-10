#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main(){
    priority_queue<int> max_pq;
    int size;
    cout<<"Enter the size";
    cin>>size;
    for(int i=0;i<size;i++)
    {
        int a;
        cin>>a;
        max_pq.push(a);
    }
    // i can pop the pq n-k times to get the ans at top of the heap
    
}