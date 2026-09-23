#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<string> result;
        
        // Loop through every character of the first word
        for (char ch : words[0]) {
            
            // Check if 'ch' is present in ALL other words
            if (all_of(words.begin() + 1, words.end(), [ch](const string& word) {
                return word.find(ch) != string::npos;
            })) {
                
                // If it is, erase one instance of 'ch' from all other words
                for (int i = 1; i < words.size(); ++i) {
                    auto it = find(words[i].begin(), words[i].end(), ch);
                    words[i].erase(it);
                }
                
                // Add the common character to our result
                result.push_back(string(1, ch));
            }
        }
        
        return result;
    }
};
