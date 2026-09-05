/* 
The Optimized (O(n)) Version : Instead of searching for the minimum inside a loop, we can create a suffix_min array starting from the end. This allows us to find both the max and min in one pass!
*/



class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int stable_index = 0 ;
        int n = nums.size();

        if ( n == 0 ) return -1;
        
        vector<int> suffix_min(n);
        suffix_min[n-1] = nums[n-1];

        for( int i = n-2 ; i >= 0 ; i-- )
        {
            suffix_min[i] = min(  nums[i] , suffix_min[i+1] );
        }


        int max_val = INT_MIN;
        for( int i = 0 ; i < n ; i++ )
        {
            max_val = max( max_val , nums[i] );

            int min_val = suffix_min[i] ;

            stable_index = max_val - min_val;

            if ( stable_index <= k )
            {
                return i;
            }     
        }

        return -1;

    }
};