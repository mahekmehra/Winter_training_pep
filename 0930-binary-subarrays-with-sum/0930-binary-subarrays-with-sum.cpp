class Solution {
public:


    int func(vector<int>& nums, int goal){

        if(goal<0) return 0;
        int left = 0;
        int count = 0;
        int sum = 0;
        for(int right = 0; right<nums.size(); right++){

            sum+=nums[right];
            while(sum>goal){
                sum-=nums[left];
                left++;
            }

            count += (right-left+1);

        }
        return count;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {


        //brute force
        /*int n = nums.size();
        int count = 0;
        for(int i=0;i<n;i++){
            int sum = 0;
            for(int j=i;j<n;j++){
                sum+=nums[j];
                if(sum==goal) count++;
            }
        }

        return count; */

        //sliding window approach
        //return func(nums,goal) - func(nums,goal-1);

        //hashmap solution
        unordered_map<int, int> prefixSumCount;

        // Initialize count of valid subarrays and current sum
        int count = 0, sum = 0;

        // Add base case: prefix sum 0 has frequency 1
        prefixSumCount[0] = 1;

        // Iterate through the array
        for (int num : nums) {
            // Add current element to prefix sum
            sum += num;

            // If (sum - goal) exists in map, add its frequency to count
            if (prefixSumCount.find(sum - goal) != prefixSumCount.end()) {
                count += prefixSumCount[sum - goal];
            }

            // Increment frequency of current prefix sum
            prefixSumCount[sum]++;
        }
        return count;
        
    }
};