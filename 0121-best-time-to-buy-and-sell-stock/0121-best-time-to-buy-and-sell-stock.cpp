class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int profit = 0;
        int small = prices[0];
        for(int i=1;i<prices.size();i++){
            if(prices[i]<small){
                small = prices[i];
            }
            profit = max(profit,prices[i]-small);
        }
        return profit;
        
    }
};