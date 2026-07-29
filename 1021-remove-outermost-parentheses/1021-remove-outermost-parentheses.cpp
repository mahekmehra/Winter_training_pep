class Solution {
public:
    string removeOuterParentheses(string s) {

        stack<char>st;
        string res = "";
        for(char i : s){
            if(i=='('){
                if(st.empty()){
                    st.push(i);
                }else{
                    res+=i;
                    st.push(i);
                }
            }else{
                st.pop();
                if(!st.empty()){
                    res+=i;
                }
            }
        }
        return res;
        
    }
};