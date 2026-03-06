class Solution {
public:

    void solve(string &s,int k){

        if(s.length()>=k){
            return;
        }

        string temp = "";

        for(int i=0;i<s.size();i++){
            char ch = s[i];
            if(ch=='z'){
                temp.push_back('a');
            }else{
                temp.push_back(ch+1);
            }
        }
        s+=temp;
        solve(s,k);
        return;
    }



    char kthCharacter(int k) {

        string s = "a";
        solve(s,k);
        return s[k-1];
   
    }
};