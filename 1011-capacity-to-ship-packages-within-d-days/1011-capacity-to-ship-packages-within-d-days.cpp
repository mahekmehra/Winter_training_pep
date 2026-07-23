class Solution {
public:

    bool check(int capacity, vector<int>& weights, int days){

        int daysUsed = 1;
        int currWeight = 0;

        for(int w : weights){

            if(currWeight + w > capacity){

                daysUsed++;
                currWeight = 0;
            }

            currWeight += w;
        }

        return daysUsed <= days;
    }




    int shipWithinDays(vector<int>& weights, int days) {

        int n = weights.size();
        int l = *max_element(weights.begin(),weights.end());
        int h = 0;
        for(int i=0;i<n;i++){
            h+=weights[i];
        }

        while(l<h){
            int mid = l+(h-l)/2;
            if(check(mid,weights,days)){
                h = mid;
            }else{
                l = mid+1;
            }
        }
        return l;
        
    }
};