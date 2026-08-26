class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        vector<int> idx;
        
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '1') {
                idx.push_back(i);
            }
        }
        
        if (idx.size() < k) {
            return "";
        }
        
        string ans = "";
        int min_len = 1e9; 
        
        for (int i = 0; i <= (int)idx.size() - k; ++i) {
            int left = idx[i];
            int right = idx[i + k - 1];
            int current_len = right - left + 1;
            
            string current_str = s.substr(left, current_len);
            
            // Update if we find a shorter window
            if (current_len < min_len) {
                min_len = current_len;
                ans = current_str;
            } 
            // If length is the same, pick the lexicographically smaller one
            else if (current_len == min_len) {
                if (current_str < ans) {
                    ans = current_str;
                }
            }
        }
        
        return ans;
    }
};
