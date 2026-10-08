class Solution {
public:
    bool isValid(string s) {
        
        /*bool changed = true;      // O(N^2) sc- O(N^2)

        while(changed){
            changed = false;
            for(int i=0;i+1<s.size();i++){
                if(s[i]=='(' && s[i+1]==')' || s[i]=='{' && s[i+1]=='}' || s[i]=='[' && s[i+1]==']' ){
                    s.erase(i,2);
                    changed = true;
                    break;
                }
            }
        }

        return s.empty();*/

        stack<char> st;
        for(char c : s){
            if(!st.empty() && (st.top()=='(' && c==')' || st.top()=='{' && c=='}' || st.top()=='[' && c ==']')){
                st.pop();
            }else{
                st.push(c);
            }
        }

        return st.empty();


    }
};