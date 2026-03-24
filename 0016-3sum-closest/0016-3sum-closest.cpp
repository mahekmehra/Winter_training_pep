class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {

        int n = nums.size();
        int ans = nums[0]+nums[1]+nums[2];

        sort(nums.begin(),nums.end());

        for(int k=0;k<n-2;k++){
            int first = nums[k];
            int i = k+1, j = n-1;
            while(i<j){
                int sum = nums[i] + nums[j] + first;

                if(sum==target) ans = sum;
                else if(abs(target-sum)<abs(target-ans)) ans = sum;
                if(sum<target) i++;
                else j--;
            }
        }
        return ans;   
    }
};