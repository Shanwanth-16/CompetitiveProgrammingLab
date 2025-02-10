#include <iostream>
#include <stack>
#include <array>
using namespace std;

int main() {
    int size;
    cout << "Enter the size of the array" << endl;
    cin >> size;
    cout << "Enter the elements of the array" << endl;
    
    int arr[size];
    int ans[size];

    for (int i = 0; i < size; i++) {
        cin >> arr[i];
        ans[i] = -1;
    }

    stack<array<int, 2> > s;

    array<int, 2> temp = {arr[0], 0};
    s.push(temp);

    int n = 1;
    while (n < size) {
        array<int, 2> a = {arr[n], n};
        
        while (!s.empty() && s.top()[0] < a[0]) {
            ans[s.top()[1]] = a[0];
            s.pop();
        }

        s.push(a);
        n++;
    }
    cout<<"ans vals:"<<endl;
    for (int i = 0; i < size; i++) {
        cout << ans[i]<<" ";
    }

    return 0;
}
