// optimal solution for this 
class Solution {
public:
    int totalFruit(vector<int>& fruits)
    {
        unordered_map<int, int> frequency;

        int left = 0;
        int answer = 0;

        for(int right = 0; right < fruits.size(); right++)
        {
            // Add current fruit to the window
            frequency[fruits[right]]++;

            // More than 2 fruit types
            while(frequency.size() > 2)
            {
                frequency[fruits[left]]--;

                // This fruit type is completely removed
                if(frequency[fruits[left]] == 0)
                {
                    frequency.erase(fruits[left]);
                }

                left++;
            }

            // Current window contains at most 2 types
            answer = max(
                answer,
                right - left + 1
            );
        }

        return answer;
    }
};