class Solution {
public:
    int pivotIndex(vector<int>& nums) {

        int n = nums.size();
        vector<int> fwd(n+2,0);
        vector<int> bwd(n+2,0);

        for(int i=1;i<n+1;i++){
            fwd[i] = fwd[i-1] + nums[i-1];
        }
        fwd[n+1] = fwd[n];

        for(int i=n;i>0;i--){
            bwd[i]= bwd[i+1] + nums[i-1];
        }
        bwd[0] = bwd[1];

        for(int i=1;i<n+1;i++){
            if(fwd[i-1]==bwd[i+1]){
                return i-1;
            }
        }
        
        return -1;
    }
};