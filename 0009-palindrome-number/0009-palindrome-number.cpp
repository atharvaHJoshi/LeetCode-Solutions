// brute force solution whre i am converting the Datatype from int to string and then using reverse

class Solution {
public:
    bool isPalindrome(int x) {

        if (x < 0) return false;

        string original_num_string = to_string( x) ;
        string rev_string = original_num_string;

        reverse( rev_string.begin() , rev_string.end() );

        if ( original_num_string == rev_string )
        {
            return 1 ;
        }
        else
        {
            return 0;
        }
    }
};