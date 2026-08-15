class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        /*int n = s.length();
        int j=0,maxlen=0;
        for(int i=0;i<n;i++){
            vector<int>hash(256,0);
            for(int j=i;j<n;j++){
                if(hash[s[j]]==1) break;
                maxlen = max(maxlen,j-i+1);
                hash[s[j]]=1;

            }
            
        }
        return maxlen;*/

        //approach 2
        
        int i=0,maxlen=0;
        vector<int>hash(256,0);
        for(int j=0;j<s.length();j++){

            while(hash[s[j]]==1){
                hash[s[i]]=0;
                i++;
            }

            maxlen = max(maxlen,j-i+1);
            hash[s[j]]=1;

        }

        return maxlen;

        
    }
};