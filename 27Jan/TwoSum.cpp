// Two sum using two pointers sorted array

#include <bits/stdc++.h>
using namespace std;


bool sol(vector<int> arr,int k,int n){
    
    int start = 0;
    int end = n-1;
    while(start<end){
        if(arr[start]+arr[end]==k) return true;
        else if(arr[start]+arr[end]>k) end--;
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

//Optmised actual approach of two sum

vector<int> twoSum(vector<int>& arr, int target) {

        unordered_map<int,int> map;
        for(int i=0;i<arr.size();i++){
            int first = arr[i];
            int second = target - first;
            if(map.find(second)!=map.end()){
                return {i,map[second]};
            }

            map[first]=i;
        }
        return {};
        
}