class Solution {
public:

    int fact(int n){
        if(n<=1) return 1;

        return n * fact(n-1);

    }


    string getPermutation(int n, int k) {

        /*int fact=1;
        vector<int> nums;
        for(int i=1;i<n;i++){
            fact=fact*i;
            nums.push_back(i);
        }
        nums.push_back(n);
        k=k-1;
        string ans="";
        while(true){
            ans=ans+to_string(nums[k/fact]);
            nums.erase(nums.begin()+k/fact);
            if(nums.size()==0){
                break;
            }
            k=k%fact;
            fact=fact/nums.size();
        }
        return ans;*/


        set<char> st;
        for(int i=0;i<n;i++){
            st.insert('1'+i);
        }

        string ans = string(n,'*');
        int currVal = 1;
        for(int i=0;i<n;i++){
            char prev = '*';
            for(auto curr : st){
                if(currVal + fact(n-i-1)>k){
                    ans[i]=curr;
                    st.erase(curr);
                    break;
                }
                currVal += fact(n-i-1);

            }
        }
        return ans;

        
    }
};