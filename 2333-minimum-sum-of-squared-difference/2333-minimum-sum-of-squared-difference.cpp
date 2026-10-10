#include <vector>
#include <cmath>
#include <numeric>
#include <algorithm>

class Solution {
public:
    long long minSumSquareDiff(std::vector<int>& nums1, std::vector<int>& nums2, int k1, int k2) {
        long long k = (long long)k1 + k2;
        int n = nums1.size();

        const int MAX_DIFF = 100001;
        std::vector<long long> bucket(MAX_DIFF, 0);
        
        // Count the frequencies of each absolute difference
        for (int i = 0; i < n; ++i) {
            bucket[std::abs(nums1[i] - nums2[i])]++;
        }
        
        // Process from the largest possible difference down to 1
        for (int d = MAX_DIFF - 1; d > 0; --d) {
            if (bucket[d] == 0) continue;
            
            // If we have enough k to reduce all differences of size 'd' to 'd-1'
            if (k >= bucket[d]) {
                k -= bucket[d];
                bucket[d - 1] += bucket[d];
                bucket[d] = 0;
            } else {
                // Otherwise, reduce as many as we can
                bucket[d - 1] += k;
                bucket[d] -= k;
                k = 0;
                break; 
            }
        }
        long long min_squared_sum = 0;
        for (long long d = 1; d < MAX_DIFF; ++d) {
            if (bucket[d] > 0) {
                min_squared_sum += bucket[d] * d * d;
            }
        }
        
        return min_squared_sum;
    }
};
