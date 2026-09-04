class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        int stability_score = 0 ;
        
        int max_val = INT_MIN ;

        for ( int i = 0 ; i < n ; i++ )
        {

            int min_val = INT_MAX;

            max_val = max( max_val , nums[i] );

            for( int j = i ; j < n ; j++ )
            {
                min_val = min( min_val , nums[j] );
            }

            stability_score = max_val - min_val;

            if ( stability_score <= k )
            {
                return i ;
            }
        }

        return -1;


    }
};