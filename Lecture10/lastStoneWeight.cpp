#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for (int i = 0; i < stones.size(); i++) {
            pq.push(stones[i]);
        }
        while (pq.size() > 1) {
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();
            if (a != b) {
                pq.push(abs(a - b));
            }
        }
        if (pq.size() == 0) {
            return 0;
        }
        return pq.top();
    }
};

int main() {
    Solution solution;
    int n;
    cout << "Enter the number of stones: ";
    cin >> n;

    vector<int> stones(n);
    cout << "Enter the weights of the stones: ";
    for (int i = 0; i < n; i++) {
        cin >> stones[i];
    }

    int result = solution.lastStoneWeight(stones);
    cout << "The weight of the last stone is: " << result << endl;

    return 0;
}
