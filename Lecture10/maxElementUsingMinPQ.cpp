 //given a min_pq find the max element
 

 #include <iostream>
 #include <vector>
 using namespace std;
 int main()
 {
    int size;
    cin>>size;
    cout<<"Enter elements in min pq order:";
    vector<int> arr(size);
    for(int i=0;i<size;i++)
    {
        cin>>arr[i];
    }
    int leaf=(size-1)/2+1;
    int max=-10000;
    for(int i=leaf;i<size;i++)
    {
        if(max<arr[i])
        {
            max=arr[i];
        }
    }
    cout<<max<<endl;
    return 0;
 }