 //brute force 

 int q = opr.size();
for(int i=0;i<q;i++){
    int l = opr[i][0];
    int r = opr[i][1];
    int val = opr[i][2];
    
    for(int j=l;j<=r;j++){
        arr[j]+=val;
    }
}

return arr;


vector<int> diffArray(vector<int>& arr, vector<vector<int>>& opr) {
        // code here
        int n = arr.size();
        vector<int> pref(n+1,0);
        
        int q = opr.size();
        for(int i=0;i<q;i++){
            int l = opr[i][0];
            int r = opr[i][1];
            int val = opr[i][2];
            
            pref[l]+=val;
            pref[r+1]-=val;
        }
        
        for(int i=1;i<n;i++){
            pref[i] += pref[i-1];
        }
        
        for(int i=0;i<n;i++){
            arr[i]+=pref[i];
        }
        
        return arr;
}