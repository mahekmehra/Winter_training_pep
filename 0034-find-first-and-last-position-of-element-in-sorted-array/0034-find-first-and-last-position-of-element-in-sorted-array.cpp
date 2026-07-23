class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {

    
        int l=0;
        int h=nums.size()-1;

        int ans = -1;
        while(l<=h){
            int mid = l+(h-l)/2;
            if(nums[mid]==target){
                ans=mid;
                h = mid - 1;
            }else if(nums[mid]<target){
                l = mid+1;
            }else{
                h = mid - 1;
            }
        }

        l=0;
        h=nums.size()-1;

        int ans2 = -1;
        while(l<=h){
            int mid = l+(h-l)/2;
            if(nums[mid]==target){
                ans2=mid;
                l = mid + 1;
            }else if(nums[mid]<target){
                l = mid+1;
            }else{
                h = mid - 1;
            }
        }

        return {ans,ans2};
    }
};