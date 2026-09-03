#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> seen;
        
        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];
            
            // Check if the complement exists in the map
            if (seen.find(complement) != seen.end()) {
                return {seen[complement], i};
            }
            
            // Store the current number and its index
            seen[nums[i]] = i;
        }
        
        return {}; // Return empty vector if no solution is found (guaranteed not to happen per constraints)
    }
};
