class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string word;
        string ans = "";
        stack<string>st;
        while(ss>>word){
            st.push(word);
        }
        while(!st.empty()){
            ans+=st.top();
            st.pop();
            ans+=" ";
        }
        ans.pop_back();
        return ans;
        
    }
};