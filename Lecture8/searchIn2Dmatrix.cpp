 #include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int searchRow(vector<vector<int>> matrix, int target) {
        int l = 0;
        int r = matrix.size() - 1;
        int n = matrix[0].size() - 1;
        int mid;
        while (l <= r) {
            mid = (l + r) / 2;
            if (target > matrix[mid][n]) {
                l = mid + 1;
            } else if (target < matrix[mid][0]) {
                r = mid - 1;
            } else {
                return mid;
            }
        }
        return -1;
    }

    bool binSearch(vector<int> arr, int target) {
        int l = 0;
        int r = arr.size() - 1;
        int mid;
        while (l <= r) {
            mid = (l + r) / 2;
            if (arr[mid] == target) {
                return true;
            } else if (arr[mid] > target) {
                r = mid - 1;
            } else if (arr[mid] < target) {
                l = mid + 1;
            }
        }
        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int index = searchRow(matrix, target);
        cout << "Row index: " << index << endl;
        if (index == -1) {
            return false;
        } else {
            return binSearch(matrix[index], target);
        }
    }
};

int main() {
    int m, n, target;

    cout << "Enter the number of rows: ";
    cin >> m;
    cout << "Enter the number of columns: ";
    cin >> n;

    vector<vector<int>> matrix(m, vector<int>(n));

    cout << "Enter the elements of the matrix row by row:" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    cout << "Enter the target value: ";
    cin >> target;

    Solution solution;
    bool result = solution.searchMatrix(matrix, target);

    if (result) {
        cout << "Target found in the matrix." << endl;
    } else {
        cout << "Target not found in the matrix." << endl;
    }

    return 0;
}
