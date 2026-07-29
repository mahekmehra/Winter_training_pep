class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        sort(strs.begin(),strs.end());
        int n = strs.size();
        string first = strs[0];
        string last = strs[n-1];
        int k = first.length();
        int i=0;
        string res="";
        while(i<k){
            if(first[i]==last[i]){
                res+=first[i];
                
            }else{
                break;
            }
            i++;
        }
        return res;




        /*int n = strs.size();
        for(int i=0;i<strs[0].size();i++){
            for(int j=1;j<n;j++){
                if(strs[j].size()<=i || strs[0][i] != strs[j][i]){
                    return strs[0].substr(0,i);
                }
            }
        }
        
        return strs[0];*/
    }
};