

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        
        int highest_altitude = 0 ;
        int current_altitude = 0 ;

        int n = gain.size();
        
        for( int i = 0 ; i < n ; i++ )
        {
            current_altitude = gain[i] + current_altitude;
            highest_altitude = max( highest_altitude , current_altitude );
        }
        
        return highest_altitude;    
    }
};