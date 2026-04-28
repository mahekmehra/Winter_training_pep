class Solution {
public:
    int minOperations(vector<int>& nums) {

        int operations = 0;
        for(int i = 0; i < (int)nums.size() - 1; i++)
        {
            if(nums[i] >= nums[i+1])
            {
                int increased = nums[i] - nums[i+1] + 1;
                nums[i+1] += increased;
                operations += increased;
            }
        }
        return operations;
        
    }
};