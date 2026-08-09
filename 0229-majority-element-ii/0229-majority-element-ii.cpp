class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> ls;
        map< int , int > mp;
        int mini =  n / 3;

        for( int i = 0 ; i < n ; i++ )
        {
            mp[ nums[i] ]++;
        }

        for( auto it : mp )
        {
            if ( it.second > mini )
            {
                ls.push_back(it.first );
            }
        }

        sort( nums.begin() , nums.end() );

        return ls;
    }
};
