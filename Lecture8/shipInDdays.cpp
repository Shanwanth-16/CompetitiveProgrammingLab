#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool check(vector<int>& arr, int d, int max) {
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
        return count <= d;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int l = 0;
        int r = 0;
        for (int i = 0; i < weights.size(); i++) {
            r += weights[i];
        }
        int mid;
        int ans;
        while (l <= r) {
            mid = (l + r) / 2;
            if (check(weights, days, mid)) {
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
    int n, days;
    cout << "Enter the number of weights: ";
    cin >> n;
    vector<int> weights(n);

    cout << "Enter the weights: ";
    for (int i = 0; i < n; i++) {
        cin >> weights[i];
    }

    cout << "Enter the number of days: ";
    cin >> days;

    Solution solution;
    int result = solution.shipWithinDays(weights, days);
    cout << "The minimum capacity required to ship within " << days << " days is: " << result << endl;

    return 0;
}
