/*Given an array of integers arr[], the task is to find the first equilibrium point in the array.

The equilibrium point in an array is an index (0-based indexing) such that the sum of all elements before that index is the same as the sum of elements after it. Return -1 if no such point exists. 

Examples:

Input: arr[] = [1, 2, 0, 3]
Output: 2 
Explanation: The sum of left of index 2 is 1 + 2 = 3 and sum on right of index 2 is 3.*/

int findEquilibrium(vector<int> &arr) {
        // code here
        int n = arr.size();
        int sum = 0;
        for(int i=0;i<n;i++){
            sum+= arr[i];
        }
        
        int  ls = 0;
        sum -= arr[0];
        if(ls==sum) return 0;
        for(int i=1;i<n;i++){
            
            ls+= arr[i-1];
            sum-= arr[i];
            if(ls==sum){
                return i;
            }
        }
        
        return -1;
}
