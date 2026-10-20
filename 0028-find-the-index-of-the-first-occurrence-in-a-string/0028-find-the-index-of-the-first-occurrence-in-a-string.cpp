class Solution {
public:
    int strStr(string haystack, string needle) {
        // Find the first occurrence of needle
        size_t found = haystack.find(needle);
        
        // If found, return the index cast to int; otherwise return -1
        return (found != string::npos) ? static_cast<int>(found) : -1;
    }
};
