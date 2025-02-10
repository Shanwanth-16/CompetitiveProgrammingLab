#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0) return 0;
        
        vector<int> maxL(n), maxR(n);
        int a = 0;
        for (int i = 0; i < n; i++) {
            a = max(a, height[i]);
            maxL[i] = a;
        }

        int b = 0;
        for (int i = n - 1; i >= 0; i--) {
            b = max(b, height[i]);
            maxR[i] = b;
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += max(0, min(maxL[i], maxR[i]) - height[i]);
        }

        return ans;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> height(n);
    for (int i = 0; i < n; i++) {
        cin >> height[i];
    }

    Solution solution;
    cout << solution.trap(height) << endl;

    return 0;
}
