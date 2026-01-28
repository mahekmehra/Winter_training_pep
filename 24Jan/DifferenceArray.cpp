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

//optimised approach


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

//Constant space Complexity

vector<int> diffArray(vector<int>& arr, vector<vector<int>>& opr) {
        
        int n = arr.size();
        for(int i=n-1;i>0;i--){
            arr[i]-=arr[i-1];
        }
        
        for(int i=0;i<opr.size();i++){
            int l = opr[i][0];
            int r = opr[i][1];
            int val = opr[i][2];
            
            arr[l]+=val;
            
            if(r+1<n) arr[r+1]-=val;
        }
        
        for(int i=1;i<n;i++){
            arr[i]+=arr[i-1];
        }
        
        return arr;
}