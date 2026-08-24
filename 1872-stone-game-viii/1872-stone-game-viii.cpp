

class Solution {
public:
    int stoneGameVIII(std::vector<int>& stones) {
        int n = stones.size();
        
        // Modify stones array in-place to become the prefix sum array
        for (int i = 1; i < n; ++i) {
            stones[i] += stones[i - 1];
        }
        
        // Initialize res with the maximum prefix sum when all stones are taken
        int res = stones[n - 1];
        
        // Traverse backwards from index n - 2 down to index 1 (corresponding to x > 1)
        for (int i = n - 2; i > 0; --i) {
            res = std::max(res, stones[i] - res);
        }
        
        return res;
    }
};
