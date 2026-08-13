
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int window_size = n - k; // Size of the subarray we leave behind
        
        // Calculate the total sum of all cards
        int total_sum = 0;
        for (int point : cardPoints) {
            total_sum += point;
        }
        
        // Edge Case: If we take all cards, return total sum
        if (k == n) return total_sum;

        int left = 0, right = 0;
        int sum = 0;
        int min_window_sum = total_sum; // We want to minimize this middle sum

        while (right < n) {
            sum += cardPoints[right];
            
            // If the window size exceeds (n - k), shrink it from the left
            if (right - left + 1 > window_size) {
                sum = sum - cardPoints[left];
                left = left + 1;
            }
            
            // Once our window reaches exactly the target size, track the minimum sum
            if (right - left + 1 == window_size) {
                min_window_sum = min(min_window_sum, sum);
            }
            
            right = right + 1;
        }

        // Maximum points = Total points minus the minimum middle points left behind
        return total_sum - min_window_sum;
    }
};