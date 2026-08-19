class Solution {

private:
    int atMost( vector<int>& nums , int k )
    {
        unordered_map< int , int > freq;

        int left = 0 ;
        int right = 0 ;
        int count = 0;

        while( right < nums.size() )
        {
            freq[nums[right]]++;

            while( freq.size() > k )
            {
                freq[nums[left]]--;
                if (freq[nums[left]] == 0 )
                {
                    freq.erase( nums[left] );
                }
                left++;
            } 

            count += ( right - left + 1 ); 
            right++;
        }
        return count;      
    }


public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMost( nums , k ) - atMost( nums , k -1 );
    }
};