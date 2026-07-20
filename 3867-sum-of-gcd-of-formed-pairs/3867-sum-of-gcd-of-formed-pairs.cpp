class Solution {
public:
    long long gcdSum(vector<int>& nums) {

        vector<int>prefixgrid;
        int mx = nums[0];
        for (int i = 0; i < nums.size(); i++) {
            mx = max(mx, nums[i]);
            prefixgrid.push_back(gcd(nums[i], mx));
        }

        sort(prefixgrid.begin(),prefixgrid.end());

        long long sum =0;
        int i=0;
        int j = prefixgrid.size()-1;
        while(i<j){
            sum+= gcd(prefixgrid[i],prefixgrid[j]);
            i++;j--;
        }

        return sum;

    }
};