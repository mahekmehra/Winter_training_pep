class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int n = s.length();
        int maxlen = 0;
        unordered_map<char,bool> mp;

        int i=0,j=0;
        while(j<n){

            if(mp[s[j]]){
                mp.erase(s[i]);
                i++;
            }else{
                mp[s[j]] = true;
                maxlen = max(maxlen,j-i+1);
                j++;

            }
        }
        return maxlen;
    }
};