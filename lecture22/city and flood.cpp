#include <iostream>
#include <set>
using namespace std;
int main() {
	int n,k;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	{
		arr[i]=i+1;
	}
	cin>>k;
	while(k--)
	{
		int won,lost;
		cin>>won;
		cin>>lost;
		for(int i=0;i<n;i++)
		{
			if(arr[i]==lost)
			{
				arr[i]=won;
			}
		}
	}
	set<int> s;
	for(int i=0;i<n;i++)
	{
		s.insert(arr[i]);
	}
	cout<<s.size()<<endl;
}