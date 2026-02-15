#include <bits/stdc++.h>
using namespace std;

void insert(vector<int>&arr, int target){
    
    if(arr.size()==0 || arr[arr.size()-1]<=target){
        arr.push_back(target);
        return;
        
    }
    
    int temp = arr[arr.size()-1];
    arr.pop_back();
    insert(arr,target);
    arr.push_back(temp);
    
}

void sortt(vector<int>& arr){
    
    if(arr.size()==1) return;
    
    int temp = arr[arr.size()-1];
    arr.pop_back();
    
    sortt(arr);
    insert(arr,temp);
}



int main()
{
    vector<int>arr = {2,9,4,0,1,5};
    sortt(arr);
    for(int i=0;i<6;i++){
        cout<<arr[i]<<" ";
    }
    

    return 0;
}