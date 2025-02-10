#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool check(vector<int>& arr, int max, int k) {
        int sum = 0;
        int count = 1;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] > max) {
                return false;
            }
            sum += arr[i];
            if (sum > max) {
                count++;
                sum = arr[i];
            }
        }
        return count <= k;
    }

    int minTime(vector<int>& arr, int k) {
        int l = arr[0];
        int r = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (l > arr[i]) {
                l = arr[i];
            }
            r += arr[i];
        }
        int mid;
        int ans;
        while (l <= r) {
            mid = (l + r) / 2;
            if (check(arr, mid, k)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};

int main() {
    int n, k;
    cout << "Enter the number of elements: ";
    cin >> n;
    vector<int> arr(n);

    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter the value of k: ";
    cin >> k;

    Solution solution;
    int result = solution.minTime(arr, k);
    cout << "The minimum time is: " << result << endl;

    return 0;
}
