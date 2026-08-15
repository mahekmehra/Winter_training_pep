class Solution {
public:
    int characterReplacement(string s, int k) {


        //BRUTE FORCE

        /*// Variable to store the maximum length of valid substring
        int maxLength = 0;
        
        // Traverse all possible substrings
        for (int i = 0; i < s.length(); i++) {
            
            // Initialize frequency array for current substring
            vector<int> freq(26, 0);
            
            // Track max frequency character in the current substring
            int maxFreq = 0;
            
            // Expand substring starting from index i
            for (int j = i; j < s.length(); j++) {
                
                // Update frequency of current character
                freq[s[j] - 'A']++;
                
                // Update the most frequent character seen so far
                maxFreq = max(maxFreq, freq[s[j] - 'A']);
                
                // Calculate total length of current substring
                int windowLength = j - i + 1;
                
                // Check how many characters we need to replace
                int replace = windowLength - maxFreq;
                
                // If number of replacements is within allowed k, update answer
                if (replace <= k) {
                    maxLength = max(maxLength, windowLength);
                }
            }
        }
        
        return maxLength;(*/


        int n = s.length();
        int left = 0;
        int maxlen = 0;
        int maxfreq = 0;
        vector<int>freq(26,0);
        for(int right=0;right<n;right++){

            freq[s[right]-'A']++;
            maxfreq = max(maxfreq,freq[s[right]-'A']);
            while((right-left+1)-maxfreq>k){
                freq[s[left]-'A']--;
                maxfreq = max(maxfreq,freq[s[left]-'A']);
                left++;
            }

            maxlen = max(maxlen,right-left+1);
        }
        return maxlen;
    }
    
};