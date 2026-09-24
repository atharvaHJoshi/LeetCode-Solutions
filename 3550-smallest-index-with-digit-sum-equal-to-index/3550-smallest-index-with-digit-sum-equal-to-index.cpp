#include <vector>

class Solution {
public:
    int smallestIndex(std::vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            int digit_sum = 0;
            int temp = nums[i];
            
            // Extract and sum up each digit
            while (temp > 0) {
                digit_sum += temp % 10;
                temp /= 10;
            }
            
            // Check if the sum matches the index
            if (digit_sum == i) {
                return i;
            }
        }
        
        // Return -1 if no such index is found
        return -1;
    }
};
