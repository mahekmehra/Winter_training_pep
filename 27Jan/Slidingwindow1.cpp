/*Max Sum Subarray of size K
Difficulty: EasyAccuracy: 49.6%Submissions: 249K+Points: 2
Given an array of integers arr[]  and a number k. Return the maximum sum of a subarray of size k.

Note: A subarray is a contiguous part of any given array.

Examples:

Input: arr[] = [100, 200, 300, 400], k = 2
Output: 700
Explanation: arr2 + arr3 = 700, which is maximum.*/

//Brute-Force

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
    
    int k;
    cin>>k;
    int ans;
    for(int i=0;i<=n-k;i++){
        int sum = 0;
        for(int j=i;j<i+k;j++){
            sum+=arr[j];
        }
        ans = max(ans,sum);
    }
    cout<<ans;
    
    return 0;
}

//optimised sliding window

int maxSubarraySum(vector<int>& arr, int k) {
        // code here
        int left = 0;
        int right = k-1;
        int sum = 0;
        for(int i=left;i<=right;i++){
            sum+=arr[i];
        }
        
        int ans = sum;
        while(right<arr.size()-1){
            sum-=arr[left];
            left++; right++;
            sum+=arr[right];
            ans=max(ans,sum);
        }
        return ans;
        
}

int maximumSumSubarray(vector<int>& arr, int k) {
        // code here
        
        long ans = INT_MIN;
        long sum = 0;
        int n = arr.size();
        int i=0,j=0;
        while(j<n){
            
            sum+=arr[j];
            
            if(j-i+1<k) j++;
            
            else if(j-i+1==k){
                ans = max(sum,ans);
                sum -= arr[i];
                i++;
                j++;
            }
        }
        
        return ans;
}