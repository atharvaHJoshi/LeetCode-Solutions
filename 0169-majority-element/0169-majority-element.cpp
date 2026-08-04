
// optimal solution
class Solution {
public:
    int majorityElement(vector<int>& arr) {
       // code here
        int count = 0;
        int element = 0 ;
        for ( int i = 0 ; i < arr.size() ; i++ )
        {
            if ( count == 0 )
            {
                count = 1;
                element = arr[i];
            }
            else if ( arr[i]  == element )
            {
                count++;
            }
            else
            {
                count--;
            }
        }
        
        int count1 = 0 ;
        // ierate throughout the whole just to check which one element is actualy correct
        for ( int i = 0 ; i < arr.size() ; i++ )
        {
            if (arr[i] == element )
            {
                count1++;
            }
        }
        
        if( count1 > ( arr.size() / 2) )
        {
            return element;
        }
        
        
        return -1;    }
};