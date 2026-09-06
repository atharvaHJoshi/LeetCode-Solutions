#include <string>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    int maxNumberOfBalloons(std::string text) {
        // Step 1: Count the frequency of all characters in the text
        std::unordered_map<char, int> counts;
        for (char c : text) {
            counts[c]++;
        }
        
        // Step 2: Calculate the maximum single words we can form for each character
        int b_count = counts['b'];
        int a_count = counts['a'];
        int l_count = counts['l'] / 2; // Needs 2 'l's per "balloon"
        int o_count = counts['o'] / 2; // Needs 2 'o's per "balloon"
        int n_count = counts['n'];
        
        // Step 3: The bottleneck (minimum value) dictates the maximum number of words
        return std::min({b_count, a_count, l_count, o_count, n_count});
    }
};
