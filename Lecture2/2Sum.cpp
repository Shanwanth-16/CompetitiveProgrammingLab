#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class A {
public:
    int val;
    int index;

    A(int val, int index) : val(val), index(index) {}

    bool operator<(const A& other) const {
        return val < other.val;
    }
};

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans(2);

        vector<A> arr;
        for (int i = 0; i < nums.size(); ++i) {
            arr.push_back(A(nums[i], i));
        }

        sort(arr.begin(), arr.end());

        int l = 0;
        int r = nums.size() - 1;

        while (l < r) {
            int sum = arr[l].val + arr[r].val;
            if (sum == target) {
                ans[0] = arr[l].index;
                ans[1] = arr[r].index;
                break;
            } else if (sum > target) {
                r--;
            } else {
                l++;
            }
        }
        return ans;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    vector<int> result = solution.twoSum(nums, target);
    cout << "Indices of two numbers are: [" << result[0] << ", " << result[1] << "]" << endl;

    return 0;
}
