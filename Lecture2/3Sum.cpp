#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<std::vector<int>> ans;
        
        std::sort(nums.begin(), nums.end());
        
        for (int i = 0; i < n; ++i) {
            
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            
            int l = i + 1;
            int r = n - 1;
            
            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                
                if (sum > 0) {
                    r--;  
                } 
                else if (sum < 0) {
                    l++;  }
                else {
                    ans.push_back({nums[i], nums[l], nums[r]});
                    
                    while (l < r && nums[l] == nums[l + 1]) {
                        l++;
                    }
                    
                    while (l < r && nums[r] == nums[r - 1]) {
                        r--;
                    }
                    
                    l++;
                    r--;
                }
            }
        }
        
        return ans;
    }
};

void printResult(const std::vector<std::vector<int>>& result) {
    for (const auto& triplet : result) {
        std::cout << "[";
        for (int num : triplet) {
            std::cout << num << " ";
        }
        std::cout << "]\n";
    }
}

int main() {
    Solution sol;
    std::vector<int> nums = {-1, 0, 1, 2, -1, -4};
    std::vector<std::vector<int>> result = sol.threeSum(nums);
    
    std::cout << "Triplets that sum to zero:\n";
    printResult(result);
    
    return 0;
}
