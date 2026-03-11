class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int n = s.length();
        if(n==0) return 0;
        int maxlen = INT_MIN;
        for(int i=0;i<n;i++){
            unordered_set<int> st;
            for(int j=i;j<n;j++){
                if(st.count(s[j]))break;
                st.insert(s[j]);
                maxlen = max(maxlen,j-i+1);
            }
        }
        return maxlen;
    }
};