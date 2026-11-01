
class Solution {
public:
    int minMoves(vector<int>& nums) {
        // Find the minimum element in the array
        int min_val = *min_element(nums.begin(), nums.end());
        
        long long moves = 0;
        // Calculate the relative difference for each element
        for (int num : nums) {
            moves += (num - min_val);
        }
        
        return moves;
    }
};
