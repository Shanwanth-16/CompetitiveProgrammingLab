#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findPlatform(vector<int>& arr, vector<int>& dep) {
        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());
        
        int n = arr.size();
        int platforms = 1, result = 1;
        int i = 1, j = 0;
        
        while (i < n && j < n) {
            if (arr[i] <= dep[j]) {
                platforms++;
                i++;
            }
            else {
                platforms--;
                j++;
            }
            result = max(result, platforms);
        }
        
        return result;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {900, 940, 950, 1100, 1500, 1800};
    vector<int> dep = {910, 1200, 1130, 1150, 1900, 2000};
    cout << "Minimum platforms required: " << sol.findPlatform(arr, dep) << endl;
    return 0;
}
