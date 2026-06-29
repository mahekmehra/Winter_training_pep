class Solution {
public:

    vector<vector<int>> dp;
    int canMake(int amount,int idx,vector<int>& coins){

        if(amount==0) return 0;
        if(amount < 0) return 1e8;
        if(idx>=coins.size()) return 1e8;

        if(dp[idx][amount]!=-1) return dp[idx][amount];

        int ans1 = 1 + canMake(amount-coins[idx],idx,coins);
        int ans2 = canMake(amount,idx+1,coins);

        return dp[idx][amount] = min(ans1,ans2);
    }




    int coinChange(vector<int>& coins, int amount) {

        int n = coins.size();
        dp.resize(coins.size(),vector<int>(amount+1,-1));
        int res = canMake(amount,0,coins);
        if(res>=1e8) return -1;
        else return res;

        
    }
};