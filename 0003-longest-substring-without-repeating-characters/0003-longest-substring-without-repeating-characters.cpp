class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int n = s.length();
        int j=0,maxlen=0;
        for(int i=0;i<n;i++){
            vector<int>hash(256,0);
            for(int j=i;j<n;j++){
                if(hash[s[j]]==1) break;
                maxlen = max(maxlen,j-i+1);
                hash[s[j]]=1;

            }
            
        }
        return maxlen;

        //approach 2
        /*int left = 0;
        unordered_set<char>st;
        int ans = 0;
        for(int right=0;right<s.size();right++){

            while(st.find(s[right]) != st.end()){
                st.erase(s[left]);
                left++;
            }

            st.insert(s[right]);
            ans = max(ans,right-left+1);
            
        }
        return ans;*/

        
    }
};