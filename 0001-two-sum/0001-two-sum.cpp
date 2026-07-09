class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        /*for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if(nums[i]+nums[j]==target){
                    return {i,j};
                }
            }
        }
        return {};*/

        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            int second = target - nums[i];
            if(mp.find(second)!=mp.end()){
                return {i,mp[second]};
            }

            mp[nums[i]] = i;
        }
        return {};
        
    }
};