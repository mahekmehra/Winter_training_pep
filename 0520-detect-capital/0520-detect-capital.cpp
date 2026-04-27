class Solution {
public:
    bool detectCapitalUse(string word) {

        int n = word.length();
    
        bool allUpper = true, allLower = true;
        
        for(char c : word){
            if(islower(c)) allUpper = false;
            if(isupper(c)) allLower = false;
        }
        
        if(allUpper || allLower) return true;
        
        // Check first uppercase, rest lowercase
        if(isupper(word[0])){
            for(int i = 1; i < n; i++){
                if(isupper(word[i])) return false;
            }
            return true;
        }
        
        return false;
    }
};