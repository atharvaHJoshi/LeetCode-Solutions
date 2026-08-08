class Solution { 
public: 
    vector<int> spiralOrder(vector<vector<int>>& matrix) { 
        // Handle empty matrix edge case safely
        if (matrix.empty() || matrix[0].empty()) return {};

        int n = matrix.size(); 
        int m = matrix[0].size(); // FIX: Changed from matrix.size() to matrix[0].size()
        
        vector<int> ans; 

        int left = 0; 
        int right = m - 1; 
        int top = 0; 
        int bottom = n - 1; 

        while (top <= bottom && left <= right) { 
            
            // 1. TOP Row: Move Left to Right
            for (int i = left; i <= right; i++) { 
                ans.emplace_back(matrix[top][i]); 
            } 
            top++; 

            // 2. RIGHT Column: Move Top to Bottom
            for (int i = top; i <= bottom; i++) { 
                ans.emplace_back(matrix[i][right]); 
            } 
            right--; 

            // 3. BOTTOM Row: Move Right to Left
            if (top <= bottom) { 
                for (int j = right; j >= left; j--) { 
                    ans.emplace_back(matrix[bottom][j]); 
                } 
                bottom--; 
            } 

            // 4. LEFT Column: Move Bottom to Top
            if (left <= right) { 
                for (int j = bottom; j >= top; j--) { 
                    ans.emplace_back(matrix[j][left]); 
                } 
                left++; 
            } 
        } 

        return ans; 
    } 
};
