#include <vector>
#include <string>

class Solution {
public:
    std::vector<int> maxDepthAfterSplit(std::string seq) {
        std::vector<int> ans;
        ans.reserve(seq.length()); // Pre-allocate memory for efficiency
        
        int depth = 0;
        for (char c : seq) {
            if (c == '(') {
                depth++;
                ans.push_back(depth % 2);
            } else {
                ans.push_back(depth % 2);
                depth--;
            }
        }
        
        return ans;
    }
};
