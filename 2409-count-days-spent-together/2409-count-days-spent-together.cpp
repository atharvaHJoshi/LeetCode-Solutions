class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        // Number of days in each month for a non-leap year
        int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        
        // Lambda function to convert "MM-DD" to a day number of the year (1 - 365)
        auto dateToDay = [&](const string& date) {
            int month = (date[0] - '0') * 10 + (date[1] - '0');
            int day = (date[3] - '0') * 10 + (date[4] - '0');
            
            int dayCount = 0;
            for (int i = 0; i < month - 1; ++i) {
                dayCount += daysInMonth[i];
            }
            return dayCount + day;
        };
        
        // Convert all string intervals into absolute day numbers
        int startAlice = dateToDay(arriveAlice);
        int endAlice = dateToDay(leaveAlice);
        int startBob = dateToDay(arriveBob);
        int endBob = dateToDay(leaveBob);
        
        // Calculate the overlap interval
        int overlapStart = max(startAlice, startBob);
        int overlapEnd = min(endAlice, endBob);
        
        // If the overlap start day is less than or equal to the end day, they intersect
        return overlapStart <= overlapEnd ? (overlapEnd - overlapStart + 1) : 0;
    }
};
