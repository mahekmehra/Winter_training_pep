class Solution {
public:

    bool check(int dist,vector<int>& position, int m){

        int curr = position[0];
        m--;
        for(int i=1;i<position.size();i++){
            if(position[i]>=curr+dist){
                curr=position[i];
                m--;
            }

            if(m==0) return true;
        }
        return false;

    }



    int maxDistance(vector<int>& position, int m) {

        int n = position.size();
        sort(position.begin(),position.end());
        int l = 1;
        int h = position[n-1]-position[0];
        int ans = -1;
        while(l<=h){
            int mid = l + (h-l)/2;
            if(check(mid,position,m)){
                ans = mid;
                l = mid+1;
            }else{
                h = mid -1;
            }
        }
        return ans;

        
    }
};