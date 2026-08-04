
// brute foce solution
class Solution {
public:
    int majorityElement(vector<int>& nums) {

        int n = nums.size();
        for ( int i = 0 ; i < n ; i++ )
        {
            int cnt = 0;

            for ( int j = 0 ; j < n ; j++ )
            {
                if ( nums[i] == nums[j] )
                {
                    cnt++;
                }
            }

            if ( (n / 2) < cnt )
            {
                return nums[i];
            } 
        }

        return {};
    }
};