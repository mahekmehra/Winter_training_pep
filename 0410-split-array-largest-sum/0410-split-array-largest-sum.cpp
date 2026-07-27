class Solution {
public:

    bool  check(int maxsum,vector<int>& nums, int k){

        int count=0;
        int sum = nums[0];
        count++;
        for(int i=1;i<nums.size();i++){
            if(sum+nums[i]>maxsum){
                count++;
                sum=0;
            }
            sum+=nums[i];
        }
        
        return(count<=k)? true : false;
    }


    int splitArray(vector<int>& nums, int k) {

        int n = nums.size();
        int low = *max_element(nums.begin(),nums.end());
        int high = accumulate(nums.begin(),nums.end(),0);
        while(low<high){
            int mid = low + (high-low)/2;
            if(check(mid,nums,k)){
                high = mid;
            }else{
                low = mid+1;
            }
        }
        return low;
        
    }
};