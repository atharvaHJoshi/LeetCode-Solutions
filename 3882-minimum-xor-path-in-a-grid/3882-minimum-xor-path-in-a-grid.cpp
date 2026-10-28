#include <vector>
#include <bitset>

using namespace std;

class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        // Max grid element is 102, so XOR path values will not exceed 1023 (10 bits: 2^10 = 1024)
        const int MAX_XOR = 1024;
        
        // dp[j] stores achievable XOR sum bitsets for column 'j'
        vector<bitset<MAX_XOR>> dp(n);
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int val = grid[i][j];
                
                if (i == 0 && j == 0) {
                    dp[0].reset();
                    dp[0].set(val);
                    continue;
                }
                
                bitset<MAX_XOR> current;
                
                // Transition 1: From Top (i - 1, j)
                if (i > 0) {
                    for (int v = 0; v < MAX_XOR; ++v) {
                        if (dp[j][v]) {
                            current.set(v ^ val);
                        }
                    }
                }
                
                // Transition 2: From Left (i, j - 1)
                if (j > 0) {
                    for (int v = 0; v < MAX_XOR; ++v) {
                        if (dp[j - 1][v]) {
                            current.set(v ^ val);
                        }
                    }
                }
                
                dp[j] = current;
            }
        }
        
        // Find the smallest reachable XOR value at the bottom-right corner (m - 1, n - 1)
        for (int v = 0; v < MAX_XOR; ++v) {
            if (dp[n - 1][v]) {
                return v;
            }
        }
        
        return 0;
    }
};