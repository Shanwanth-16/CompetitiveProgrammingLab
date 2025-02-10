#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class A {
public:
    int val;
    int x, y;
    
    A(int v, int x1, int y1) {
        val = v;
        x = x1;
        y = y1;
    }

    bool operator>(const A& other) const {
        return val > other.val;
    }
};

int main() {
    int m, n, k;
    cout << "Enter the dimensions of the matrix: ";
    cin >> m >> n;
    
    vector<vector<int> > matrix(m, vector<int>(n));
    cout << "Enter the value of k: ";
    cin >> k;
    
    cout << "Enter the elements of the matrix:" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
    priority_queue<A, vector<A>, greater<A> > min_heap;
    min_heap.push(A(matrix[0][0], 0, 0));
    int count = 0;
    int ans = -1;

    while (count < k) {
        A current = min_heap.top();
        min_heap.pop();
        
        ans = current.val;
        int i = current.x;
        int j = current.y;
        if (j + 1 < n) {
            min_heap.push(A(matrix[i][j + 1], i, j + 1));
        }
        if (i + 1 < m) {
            min_heap.push(A(matrix[i + 1][j], i + 1, j));
        }

        count++;
    }

    cout << "The " << k << "-th smallest element is: " << ans << endl;

    return 0;
}
