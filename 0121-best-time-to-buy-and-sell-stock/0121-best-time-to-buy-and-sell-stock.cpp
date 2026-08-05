//brute force Solution

class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int maxProfit = 0 ;
        int n = prices.size();
        int minPrice = prices[0] ;

        int cost ;

        for ( int i = 0 ; i < n ; i++ )
        {
            cost = prices[i] - minPrice ;

            maxProfit = max( cost , maxProfit );

            minPrice = min( minPrice ,  prices[i] );
        }

        return maxProfit;
        
    }
};