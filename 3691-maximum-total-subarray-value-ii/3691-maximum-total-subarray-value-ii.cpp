#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
#include <tuple>

using namespace std;

class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();
        int K = log2(n) + 1;
        
        vector<vector<int>> stMax(n, vector<int>(K));
        vector<vector<int>> stMin(n, vector<int>(K));
        vector<int> lg(n + 1, 0);
        
        for (int i = 2; i <= n; i++) lg[i] = lg[i / 2] + 1;
        for (int i = 0; i < n; i++) {
            stMax[i][0] = nums[i];
            stMin[i][0] = nums[i];
        }
        
        for (int j = 1; j < K; j++) {
            for (int i = 0; i + (1 << j) <= n; i++) {
                stMax[i][j] = max(stMax[i][j - 1], stMax[i + (1 << (j - 1))][j - 1]);
                stMin[i][j] = min(stMin[i][j - 1], stMin[i + (1 << (j - 1))][j - 1]);
            }
        }
        
        auto getVal = [&](int l, int r) {
            int j = lg[r - l + 1];
            int mx = max(stMax[l][j], stMax[r - (1 << j) + 1][j]);
            int mn = min(stMin[l][j], stMin[r - (1 << j) + 1][j]);
            return (long long)(mx - mn);
        };
        
        // Priority queue storing elements as {value, left_index, right_index}
        priority_queue<tuple<long long, int, int>> pq;
        for (int l = 0; l < n; l++) {
            pq.push({getVal(l, n - 1), l, n - 1});
        }
        
        long long totalValue = 0;
        while (k-- > 0 && !pq.empty()) {
            auto [val, l, r] = pq.top();
            pq.pop();
            totalValue += val;
            if (r > l) {
                pq.push({getVal(l, r - 1), l, r - 1});
            }
        }
        
        return totalValue;
    }
};
