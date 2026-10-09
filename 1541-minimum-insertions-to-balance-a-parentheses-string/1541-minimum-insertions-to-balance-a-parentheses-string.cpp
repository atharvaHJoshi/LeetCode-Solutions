#include <string>
#include <algorithm>

class Solution {
public:
    int minInsertions(string s) {
        int res = 0; // Total insertions needed
        int need = 0; // Number of ')' needed to balance current '('

        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(') {
                need += 2; // Each '(' needs two ')'
                
                // If 'need' is odd, we have an unbalanced ')' expectation, 
                // so we insert a ')' right now and adjust.
                if (need % 2 != 0) {
                    res++;
                    need--;
                }
            } else { // s[i] == ')'
                need--; // Consumpt one ')'
                
                // If need goes below 0, we have an extra ')' with no opening '(',
                // so we need to insert a '(' and reset need to 1 (since this ')' still counts as one of the two needed)
                if (need < 0) {
                    res++;
                    need = 1; // It acts as one ')' for a newly inserted '('
                }
            }
        }

        // Add any remaining ')' needed for unmatched '('
        return res + need;
    }
};
