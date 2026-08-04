
// better solution
class Solution {
public:
    int majorityElement(vector<int>& nums) {

        unordered_map < int , int > hashmap;

        int n = nums.size();

        for ( int i = 0 ; i < n ; i++ )
        {
            hashmap[ nums[i] ]++;
        }

        for ( auto it : hashmap )
        {
            if ( it.second > ( n / 2) )
            {
                return it.first;
            }
        }

        return {};
    }
};