#include <vector>

using namespace std;

class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> ans(k, 0);
        
        // dp[i][r] = number of contiguous subarrays ending at index i 
        // whose product modulo k is equal to r
        vector<vector<long long>> dp(n, vector<long long>(k, 0));

        for (int i = 0; i < n; ++i) {
            int numMod = nums[i] % k;

            // Start a brand new subarray consisting only of nums[i]
            dp[i][numMod] += 1;

            // Transition: Extend all subarrays that ended at the previous index (i - 1)
            if (i > 0) {
                for (int r = 0; r < k; ++r) {
                    if (dp[i - 1][r] > 0) {
                        int nextMod = (r * numMod) % k;
                        dp[i][nextMod] += dp[i - 1][r];
                    }
                }
            }

            // Accumulate counts from the current position into the final answer array
            for (int r = 0; r < k; ++r) {
                ans[r] += dp[i][r];
            }
        }

        return ans;
    }
};
