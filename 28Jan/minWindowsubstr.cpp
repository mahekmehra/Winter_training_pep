//brute force

bool check(string &sub,string &t){

        unordered_map<char,int>mp;
        for(char ch : t){
            mp[ch]++;
        }
        for(char ch : sub){
            if(mp.find(ch)!=mp.end()){
                mp[ch]--;
            }
        }

        for (auto i = mp.begin(); i != mp.end(); i++){
            if(i->second>0){
                return false;
            }
        }
        return true;
}

string minWindow(string s, string t) {

    int ans = INT_MAX;
    string res = "";
    int n = s.length();
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){

            string sub = s.substr(i,j-i+1);
            if(check(sub,t)){
                int count = sub.length();
                if(count<ans){
                    ans = count;
                    res = sub;
                }
            }
        }
    }
    return res;
    
}

//sliding window

string smallestWindow(string &s, string &t) {
        
        int len1 = s.length();
        int len2 = t.length();
    
        if (len1 < len2)
            return "";
    
        vector<int> key(256, 0);
        vector<int> sub(256, 0);
    

        for (int i = 0; i < len2; i++)
            key[p[i]]++;
    
        int start = 0, start_idx = -1, min_len = INT_MAX;
    
        int count = 0;
    
        for (int j = 0; j < len1; j++){
       
            sub[s[j]]++;
    
           
            if (key[s[j]] != 0 && sub[s[j]] <= key[s[j]]){
                count++;
            }
    
            if (count == len2){
                // Try to minimize the window
                while (sub[s[start]] > key[s[start]] ||  key[s[start]] == 0){
                    if (sub[s[start]] > key[s[start]]){
                        sub[s[start]]--;
                    }
                    start++;
                }
    

                int len = j - start + 1;
                if (min_len > len){
                    min_len = len;
                    start_idx = start;
                }
            }
        }
    
        if (start_idx == -1)
            return "";
    
        return s.substr(start_idx, min_len);
}