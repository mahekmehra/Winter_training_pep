/*Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

A subarray is a contiguous non-empty sequence of elements within an array.*/

int subarraySum(vector<int>& nums, int k) {

        /*int count = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            int sum =0;
            for(int j=i;j<n;j++){
                sum+=nums[j];
                if(sum==k){
                    count++;
                }
            }
        }
        return count;*/

        int n = nums.size();
        unordered_map<int,int> map;
        int sum =0,cnt = 0;
        map[0]=1;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            int remain = sum - k;
            if(map.find(remain)!=map.end()){
                cnt += map[remain];
            }
            map[sum]++;
        }
        return cnt;
}