/*Given an array arr and q queries. Write a program to find the floor value of the mean in the range l to r for each query in a new line.
Queries are given by an array of queries[] of size 2*q. Here queries[2*i] denote l and queries[2*i+1] denote r for i-th query.

Examples:

Input : arr[] = [1, 2, 3, 4, 5] and q[] = [0, 2, 1, 3, 0, 4]
Output : [2, 3, 3]
Explanation: Here we can see that the array of integers is [1, 2, 3, 4, 5]. Query 1: L = 0 and R = 2 Sum = 6 Integer Count = 3 So, Mean is 2*/



class Solution {                 //PREFIX SUM VARIATION
  public:
    vector<int> findMean(vector<int>& arr, vector<int>& q) {
        
        int n = arr.size();
        vector<int> pref(n,0);
        int sum = 0;
        for(int i=0;i<n;i++){
            sum +=  arr[i];
            pref[i] = sum;
            
        }
        
        vector<int> ans;
        
        int Q = q.size();
        for(int i=0;i<Q;i+=2){
            int l = q[i];
            int r = q[i+1];
            int sum;
            if(l!=0){
                sum = pref[r]-pref[l-1];
            }else{
                sum = pref[r];
            }
            ans.push_back(sum/(r-l+1));
        }
        return ans;
    }
};