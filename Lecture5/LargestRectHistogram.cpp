#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class A {
public:
    int index;
    int val;
    A(int i, int v) {
        index = i;
        val = v;
    }
};

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<A> s;
        int maxArea = 0;
        
        for (int i = 0; i < n; i++) {
            int start = i;
            A obj(i, heights[i]);

            while (!s.empty() && s.top().val > heights[i]) {
                int h = s.top().val;
                int j = s.top().index;
                s.pop();
                start = j;
                int width = i - j;
                int curArea = h * width;
                maxArea = max(maxArea, curArea);
            }
            
            obj.index = start;
            s.push(obj);
        }

        while (!s.empty()) {
            int h = s.top().val;
            int j = s.top().index;
            s.pop();
            int width = n - j;
            int curArea = h * width;
            maxArea = max(maxArea, curArea);
        }

        return maxArea;
    }
};

int main() {
    int n;
    cout << "Enter the number of bars: ";
    cin >> n;

    vector<int> heights(n);
    cout << "Enter the heights of the bars: ";
    for (int i = 0; i < n; i++) {
        cin >> heights[i];
    }

    Solution sol;
    int result = sol.largestRectangleArea(heights);
    cout << "The largest rectangle area is: " << result << endl;

    return 0;
}
