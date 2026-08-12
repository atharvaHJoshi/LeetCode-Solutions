//  better solution with TC of O( N + N)


class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0 ;
        int right = 0 ;
        int maxLen = 0 ;
        int maxFreq = 0;
        vector<int> hashmap(26, 0);
        while ( right < s.size() )
        {
            hashmap[s[right]-'A']++;
            maxFreq = max(maxFreq, hashmap[s[right] - 'A']);


            if ( ((right - left + 1 ) - maxFreq) > k )
            {
                hashmap[s[left] - 'A']--;
                left = left + 1 ;
            }

            if ( (right - left + 1 ) - maxFreq <= k )
            {
                maxLen = max( maxLen , right - left + 1 );
            } 

            right++;
        }

        return maxLen;
    }
};