// tabulation method DP

class Solution {
public:
    int rob(vector<int>& nums) {

        int n = nums.size(); 

        // create one 1D - DP vector for the tabulation method 
        vector<int> dp(n);

        // need to handle this test cases for small inputs for the n
        if ( n == 0 ) return 0;
        if ( n == 1 ) return nums[0];   

        // initialize the smallest possible ans
        dp[0] = nums[0];
        dp[1] = max( nums[0], nums[1] );


        // running the loop from i = 2 
     for( int i = 2 ; i < n ; i++ )
     {
        dp[i] = max( dp[i-2] + nums[i] , dp[i-1] );
     }  

     
     return dp[n-1];  
    }
};