/*Given that u have a sorted array that the difference of two elements is equal to target*/

#include <bits/stdc++.h>
using namespace std;


bool sol(vector<int> arr,int k,int n){
    
    int start = 0;
    int end = 1;
    while(start<end){
        if(arr[end]-arr[start]==k) return true;
        else if(arr[end]-arr[start]<k) end++;
        else start++;
    }
    
    return false;
}

int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    int k;
    cin>>k;
    cout<<sol(arr,k,n);
    
    return 0;
}