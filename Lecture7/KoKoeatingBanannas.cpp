#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    long check(std::vector<int> piles, int speed) {
        long hours = 0;
        for (int i = 0; i < piles.size(); i++) {
            hours += (piles[i] + speed - 1) / speed;
        }
        return hours;
    }

    int binarySearch(std::vector<int> piles, int low, int high, int h) {
        while (low < high) {
            int mid = (low + high) / 2;
            long hoursRequired = check(piles, mid);

            if (hoursRequired > h) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low;
    }

    int minEatingSpeed(std::vector<int>& piles, int h) {
        int maxPile = *std::max_element(piles.begin(), piles.end());
        return binarySearch(piles, 1, maxPile, h);
    }
};

int main() {
    Solution solution;
    std::vector<int> piles = {3, 6, 7, 11};
    int h = 8;
    int minSpeed = solution.minEatingSpeed(piles, h);
    std::cout << "Minimum eating speed: " << minSpeed << std::endl;
    return 0;
}
