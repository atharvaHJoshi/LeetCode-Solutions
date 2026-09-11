#include <vector>
#include <algorithm>

class Solution {
public:
    int totalNumbers(std::vector<int>& digits) {
        int count[10] = {0};
        for (int d : digits) {
            count[d]++;
        }
        int uniqueEvenCount = 0;
        for (int num = 100; num <= 998; num += 2) {
            int h = num / 100;
            int t = (num / 10) % 10;
            int u = num % 10;
            count[h]--;
            count[t]--;
            count[u]--;
            if (count[h] >= 0 && count[t] >= 0 && count[u] >= 0) {
                uniqueEvenCount++;
            }
            count[h]++;
            count[t]++;
            count[u]++;
        }
        return uniqueEvenCount;
    }
};
