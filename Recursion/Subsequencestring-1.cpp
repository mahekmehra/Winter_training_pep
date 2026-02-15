void rec(vector<string> &res,string temp,string &s,int idx){
        
        if(idx==s.length()){
            if(temp!=" ") res.push_back({temp});
            return;
        
        }
        
        temp.push_back(s[idx]);
        rec(res,temp,s,idx+1);
        temp.pop_back();
        rec(res,temp,s,idx+1);
        
    }
    
  
  
  
    vector<string> AllPossibleStrings(string s) {
        // Code here
        vector<string> res;
        string temp = "";
        rec(res,temp,s,0);
        sort(res.begin(),res.end());
        return res;
        
        
    }