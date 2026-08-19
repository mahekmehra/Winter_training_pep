class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        //approach 1 O(nlogn)
        /*int n = nums.size();
        if(n==0) return 0;
        int ans = 1;
        int cnt = 1;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-1;i++){

            if(nums[i]==nums[i+1]) continue;

            if(nums[i]+1==nums[i+1]){
                cnt++;
            }else{
                cnt = 1;
            }
            ans = max(ans,cnt);
        }
        return ans;*/

        int n = nums.size();
        if(n==0) return 0;
        unordered_set<int> st(nums.begin(),nums.end());
        int longest = 0;
        for(int num : st){
            if(st.find(num-1)==st.end()){
                int length = 1;
                while(st.find(num+length)!=st.end()){
                    length++;
                }
                longest = max(length,longest);
            }
        }
        return longest;
    }
};