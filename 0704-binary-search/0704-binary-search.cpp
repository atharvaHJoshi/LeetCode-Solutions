class Solution {
public:
    int search(vector<int>& nums, int target) {
    //sort( nums.begin() , nums.end() );
    
    int left = 0 ;
    int right = nums.size() - 1;
    //int right = *max_element( nums.begin() , nums.end() );

     while ( left <= right )
     {
        int mid  = left + ( right - left ) / 2 ;
        if ( nums[mid] == target )
        {
            return mid;
        }
        else if ( nums[mid] < target )
        {
            left = mid + 1 ; 
        }
        else
        {
            right = mid - 1 ;
        }
     }


    return -1;
    }
};