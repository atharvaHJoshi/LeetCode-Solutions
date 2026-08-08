// better solution 

class Solution {
public:

    void setZeroes(vector<vector<int>>& matrix) {
        
        if (matrix.empty() || matrix[0].empty()) return;

        int n = matrix.size() ;
        int m = matrix[0].size() ;   


        //create two vector array of
        vector<int> row( n , 0 );
        vector<int> col( m , 0 );
        
        // scan and find 0 and then marks i and j of it as 1
        for ( int i = 0 ; i < n ; i++ )
        {
            for ( int j = 0 ; j < m ; j++ )
            {
                if ( matrix[i][j] == 0 )
                {
                    row[i] = 1;
                    col[j] = 1;
                }
            }
        } 


        //look at every cell where row and col marked as 0
        for( int i = 0 ; i < n ; i++ )
        {
            for(int j = 0 ; j < m ; j++ )
            {
                if (  row[i] || col[j] )
                {
                    matrix[i][j] = 0;
                }
            }
        }
  }
};