/*Given an integer array nums and an integer k, return the number of non-empty subarrays that have a sum divisible by k.

A subarray is a contiguous part of an array.*/

int subarraysDivByK(vector<int>& nums, int k) {

        /*int n = nums.size();
        int cnt = 0;
        for(int i=0;i<n;i++){
            int sum = 0;
            for(int j=i;j<n;j++){
                sum+=nums[j];
                if(sum%k==0){
                    cnt++;
                }

            }
        }
        return cnt;*/

        int n = nums.size();
        unordered_map<int,int> mp;
        int prefsum = 0, cnt = 0;
        mp[0] = 1;
        for(int j=0;j<n;j++){
            prefsum += nums[j];
            int remain = prefsum % k;
            if(remain<0) remain+=k;
            if(mp.find(remain)!=mp.end()){
                cnt+= mp[remain];
            }
            mp[remain]++;
        }

        return cnt;
        
}