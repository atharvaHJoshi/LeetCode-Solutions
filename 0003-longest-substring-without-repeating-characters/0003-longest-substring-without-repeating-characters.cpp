// Solved using the sliding window + two pointer array

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size(); 
        int maxLen = 0; 
        vector<int> hash(256, -1); 
        int left = 0, right = 0; 

        while (right < n) { 
            if (hash[s[right]] >= left) { 
                left = hash[s[right]] + 1; 
            } 
            
            int len = right - left + 1; 
            maxLen = max(len, maxLen); 
            hash[s[right]] = right; // Record the current position
            right++; 
        } 
        return maxLen; 
    }
};