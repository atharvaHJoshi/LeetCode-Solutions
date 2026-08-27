
class Solution {
private:
    void backtrack(int start, int n, int k, std::vector<int>& current, std::vector<std::vector<int>>& result) {
        // Base case: If the combination is full, save it
        if (current.size() == k) {
            result.push_back(current);
            return;
        }

        // Optimization (Pruning):
        // Remaining slots needed = k - current.size()
        // We only loop up to 'n - (k - current.size()) + 1' because any index 
        // beyond that won't have enough remaining elements to complete the combination.
        int upper_bound = n - (k - current.size()) + 1;
        
        for (int i = start; i <= upper_bound; ++i) {
            current.push_back(i);                  // Choose the current number
            backtrack(i + 1, n, k, current, result); // Move to the next number
            current.pop_back();                   // Backtrack
        }
    }

public:
    std::vector<std::vector<int>> combine(int n, int k) {
        // Optimize standard I/O operations for faster runtime on LeetCode
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        std::vector<std::vector<int>> result;
        std::vector<int> current;
        
        backtrack(1, n, k, current, result);
        
        return result;
    }
};
