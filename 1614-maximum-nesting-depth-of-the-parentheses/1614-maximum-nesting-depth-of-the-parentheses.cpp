class Solution {
public:
    int maxDepth(string s) {
        int current_depth = 0 ;
        int max_depth = 0 ;

        for( char c : s )
        {
            if ( c == '(' )
            {
                current_depth++;

                max_depth = max( current_depth , max_depth );
            }
            else if( c == ')' )
            {
                current_depth--;
            }
        }    

            return max_depth;   
    }
};