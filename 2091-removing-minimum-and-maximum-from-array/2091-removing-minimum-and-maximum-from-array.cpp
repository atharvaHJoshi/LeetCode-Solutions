
class Solution {
public:
    int minimumDeletions(std::vector<int>& nums) {
        int n = nums.size();
        
        // Find indices of the minimum and maximum elements
        int min_idx = std::min_element(nums.begin(), nums.end()) - nums.begin();
        int max_idx = std::max_element(nums.begin(), nums.end()) - nums.begin();
        
        // Ensure i represents the smaller index and j represents the larger index
        int i = std::min(min_idx, max_idx);
        int j = std::max(min_idx, max_idx);
        
        // Strategy 1: Delete both from the front
        int front_only = j + 1;
        
        // Strategy 2: Delete both from the back
        int back_only = n - i;
        
        // Strategy 3: Delete one from the front and one from the back
        int both_sides = (i + 1) + (n - j);
        
        // Return the minimum deletions among the three choices
        return std::min({front_only, back_only, both_sides});
    }
};
