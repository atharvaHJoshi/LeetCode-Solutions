#include <string>
#include <vector>
#include <set>
#include <string_view>
#include <algorithm>

class Solution {
public:
    std::vector<std::string> braceExpansionII(std::string expression) {
        int i = 0;
        std::set<std::string> result_set = parse(expression, i);
        return std::vector<std::string>(result_set.begin(), result_set.end());
    }

private:
    std::set<std::string> parse(const std::string& expr, int& i) {
        std::vector<std::set<std::string>> groups = {{""}}; // Stores segments separated by commas
        
        while (i < expr.length() && expr[i] != '}') {
            if (expr[i] == '{') {
                i++; // Skip '{'
                std::set<std::string> sub_res = parse(expr, i);
                i++; // Skip '}'
                
                // Concatenate sub-result with the last element of the current group
                groups.back() = combine(groups.back(), sub_res);
            } 
            else if (expr[i] == ',') {
                i++; // Skip ','
                groups.push_back({""}); // Start a new union group
            } 
            else {
                // Read a plain string of lowercase characters
                std::string word = "";
                while (i < expr.length() && std::isalpha(expr[i])) {
                    word += expr[i++];
                }
                groups.back() = combine(groups.back(), {word});
            }
        }
        
        // Take the union of all comma-separated groups
        std::set<std::string> merged;
        for (const auto& group : groups) {
            merged.insert(group.begin(), group.end());
        }
        return merged;
    }

    // Computes the Cartesian product (concatenation) of two sets
    std::set<std::string> combine(const std::set<std::string>& s1, const std::set<std::string>& s2) {
        std::set<std::string> res;
        for (const auto& str1 : s1) {
            for (const auto& str2 : s2) {
                res.insert(str1 + str2);
            }
        }
        return res;
    }
};
