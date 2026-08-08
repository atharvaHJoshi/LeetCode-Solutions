// OPTIMAL SOLUTION
// decreasing the space complexity to O( n^2 ) from O(1) 
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {

    int n = matrix.size();
    
    // transpose of matrix without creating any extra array 
    for ( int i = 0 ; i < n - 1 ; i++ )
    {
        for ( int j = i + 1 ; j < n ; j++ )
        {
            swap( matrix[i][j] , matrix[j][i]);
        }
    }

    //revsering the array
    for ( int i = 0 ; i < n ; i++ )
    {
        reverse ( matrix[i].begin() , matrix[i].end() );
    }

    }
};