#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> generateMatrix(int n) {
        std::vector<std::vector<int>> matrix(n, std::vector<int>(n, 0));
        
        int top = 0, bottom = n - 1;
        int left = 0, right = n - 1;
        int num = 1;
        
        while (top <= bottom && left <= right) {
            // 1. Fill top row (left to right)
            for (int i = left; i <= right; ++i) {
                matrix[top][i] = num++;
            }
            top++;
            
            // 2. Fill right column (top to bottom)
            for (int i = top; i <= bottom; ++i) {
                matrix[i][right] = num++;
            }
            right--;
            
            // 3. Fill bottom row (right to left)
            if (top <= bottom) {
                for (int i = right; i >= left; --i) {
                    matrix[bottom][i] = num++;
                }
                bottom--;
            }
            
            // 4. Fill left column (bottom to top)
            if (left <= right) {
                for (int i = bottom; i >= top; --i) {
                    matrix[i][left] = num++;
                }
                left++;
            }
        }
        
        return matrix;
    }
};
