class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {

        //brute force
        /*int n = nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(nums[j]==nums[i]){
                    return true;
                }
            }
        }
        return false;*/
        
        //optimal approach  
        int n =nums.size();
        unordered_set<int>st;
        for(int i=0;i<n;i++){
            st.insert(nums[i]);
        }

        return (n!=st.size())? true : false;


        
    }
};