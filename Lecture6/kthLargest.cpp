#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class maxHeap {
public:
    vector<int> h;

    void heapify(int index, int n) {
        int largest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < n && h[left] > h[largest]) {
            largest = left;
        }

        if (right < n && h[right] > h[largest]) {
            largest = right;
        }

        if (largest != index) {
            swap(h[index], h[largest]);
            heapify(largest, n);
        }
    }

    void buildHeap() {
        int n = h.size();
        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(i, n);
        }
    }

    int pop() {
        if (h.empty()) {
            throw runtime_error("Heap is empty");
        }

        int ans = h[0];
        h[0] = h.back();
        h.pop_back();
        heapify(0, h.size());
        return ans;
    }

    maxHeap(vector<int> nums) {
        h = nums;
        buildHeap();
    }
};

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        maxHeap obj(nums);
        int ans = 0;

        for (int i = 0; i < k; i++) {
            ans = obj.pop();
        }

        return ans;
    }
};

int main() {
    vector<int> nums = {3, 2, 1, 5, 6, 4};
    int k = 2;

    Solution solution;
    int result = solution.findKthLargest(nums, k);

    cout << "The " << k << "-th largest element is: " << result << endl;

    return 0;
}
