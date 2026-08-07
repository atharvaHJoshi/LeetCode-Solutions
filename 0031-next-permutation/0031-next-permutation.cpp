// optimal solution

class Solution {
public:
    void nextPermutation(vector<int>& nums) {

        int n = nums.size();
        int index = -1;

        // finding break point 
        for ( int i = n - 2 ; i >= 0 ; i-- )
        {
            if ( nums[i] < nums[i + 1] )
            {
                index = i ;
                break;
            }
        }

        //and if no breakpoint and if array is of largest sorted orderd
        if ( index == -1 )
        {
            reverse( nums.begin() , nums.end() );
            return ;
        }

        // find the smallest greater element after the breakpoint range 
        for ( int i = n - 1 ; i > index ; i-- )
        {
            if ( nums[i] > nums[index] )
            {
                swap ( nums[i] , nums[index] );
                break;
            }
        }

        // revser the suffix after the breakpopint
        reverse( nums.begin() + index + 1 , nums.end() );
        
        //return nums;

    }
};