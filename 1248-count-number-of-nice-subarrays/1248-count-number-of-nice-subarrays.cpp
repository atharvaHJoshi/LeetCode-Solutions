// Solve using SLIDING WINDOW + TWO PTR 

class Solution {
public:

    int atMost( vector<int>& nums, int k )
    {
        int left = 0 , right = 0;
        int oddCount = 0 , cnt = 0;

        if( k < 0 )
            return 0;


        while ( right < nums.size() )
        {
            // adding the another num
            if( nums[right]%2 == 1 )
            {
                oddCount++;
            }

            // too many odd nums
            while( oddCount > k )
            {
                if ( nums[left]%2 == 1)
                {
                    oddCount--;
                }
                left++;
            }

            cnt = cnt + ( right - left + 1 );
            right++;   
        }

        return cnt;
    } 

    int numberOfSubarrays(vector<int>& nums, int k) {        
        return atMost(nums , k)  - atMost( nums , k - 1 );
    }
};