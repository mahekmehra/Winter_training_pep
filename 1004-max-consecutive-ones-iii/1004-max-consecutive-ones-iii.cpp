class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {

        //brute force
        
        int n = nums.size();
        /*int maxlen = 0;
        for(int i=0;i<n;i++){
            int temp = k;
            for(int j=i;j<n;j++){

                if(nums[j]==0){
                    if(temp) temp--;
                
                    else break;
                }

                maxlen = max(maxlen,j-i+1);
            }
        }
        return maxlen;*/

        //optimal approach
        int left = 0;
        int maxlen = 0;
        int zerocount = 0;
        for(int right=0;right<n;right++){

            if(nums[right]==0) zerocount++;

            while(zerocount>k){
                if(nums[left]==0) zerocount--;
                left++;
            }

            maxlen=max(maxlen,right-left+1);
        }

        return maxlen;
        
    }
};