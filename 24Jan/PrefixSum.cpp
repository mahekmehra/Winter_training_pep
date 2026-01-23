#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; 
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    vector<int> pref(n,0);
    int sum = 0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        pref[i] = sum;
    }
    
    int Q;
    cin>>Q;
    for(int i=0;i<Q;i++){
        int l,r;
        cin>>l>>r;
        if(l!=0){
            cout<<(pref[r]-pref[l-1])<<endl;
        }else{
            cout<<(pref[r])<<endl;
        }
    }
    
    return 0;
}

/* TC - O(N+Q)
   SC - O(N)  */