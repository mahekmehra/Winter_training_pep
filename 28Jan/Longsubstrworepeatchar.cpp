/*You are given a string s. You have to find the length of the longest substring with all distinct characters. 

Examples:

Input: s = "geeksforgeeks"
Output: 7
Explanation: "eksforg" is the longest substring with all distinct characters.*/

int longestUniqueSubstr(string &s) {
        
        unordered_map<char, int> mp;
    
        int left = 0;
        int ans = 0;
    
        for (int right = 0; right < s.length(); right++) {
            
            if (mp.find(s[right]) != mp.end() && mp[s[right]] >= left) {
                left = mp[s[right]] + 1;
            }
    
            mp[s[right]] = right;
            ans = max(ans, right - left + 1);
        }
    
        return ans;
        
}
    
    //checking condition => whi window me uss character ka last occurence aa raha hai ya nahi