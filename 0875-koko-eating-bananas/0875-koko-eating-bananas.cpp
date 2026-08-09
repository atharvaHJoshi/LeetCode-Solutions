class Solution {
private:
    long long calculateHours(const vector<int>& piles, int speed) { 
        long long hours = 0; 
        for (int bananas : piles) { 
            // 1. Divide by speed, not hours!
            hours += (bananas + speed - 1) / speed; 
        } 
        return hours; 
    } 

public:
    int minEatingSpeed(vector<int>& piles, int h) {
    
    int min_speed = 1;
    int high = *max_element( piles.begin() , piles.end() );

    while ( min_speed <= high )
    {
        int mid = min_speed + ( high - min_speed )  / 2  ;

        long long totalHours = calculateHours( piles , mid );

        if ( totalHours <= h )
        {
            high = mid - 1 ;
        }
        else
        {
            min_speed = mid + 1 ;
        }
    }
     return min_speed;
    }
};