class Solution {
public:
    int mySqrt(int x) {
        // Base cases for 0 and 1
        if (x < 2) {
            return x;
        }
        
        int left = 2;
        int right = x / 2;
        int ans = 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            long long num = (long long)mid * mid; // Prevent overflow
            
            if (num == x) {
                return mid;
            } else if (num < x) {
                ans = mid; // mid is a potential answer
                left = mid + 1; // Search the right half
            } else {
                right = mid - 1; // Search the left half
            }
        }
        
        return ans;
    }
};
