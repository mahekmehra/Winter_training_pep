class Solution {
public:

    vector<vector<int>> dp;

    int recur(vector<int>& nums, int target,int i,int sum){

        if(i== nums.size()){
            return sum==target;
        }

        if(dp[i][sum+1000]!=-1){
            return dp[i][sum+1000];
        }

        
        int ways = recur(nums,target,i+1,sum+nums[i]) + recur(nums,target,i+1,sum-nums[i]);
        return dp[i][sum+1000] = ways;
        

    }


    int findTargetSumWays(vector<int>& nums, int target) {

        
        dp.assign(nums.size(), vector<int>(2001, -1));
        return recur(nums,target,0,0); 
    }
};