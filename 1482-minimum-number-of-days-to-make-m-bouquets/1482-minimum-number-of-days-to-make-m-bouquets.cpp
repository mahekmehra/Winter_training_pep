class Solution {
public:

    bool pos(int minthday,vector<int>& bloomDay,int bouquets,int flowers){

        int totalflowers = 0;
        int totalbouquets = 0;
        for(int day : bloomDay){

            if(day>minthday){
                totalflowers=0;
            }else{
                totalflowers++;
            }
            if(totalflowers==flowers){
                totalbouquets++;
                totalflowers=0;
            }
            
        }

        return (totalbouquets>=bouquets)? true : false;
    }




    int minDays(vector<int>& bloomDay, int m, int k) {

        int ans = -1;
        int l = *min_element(bloomDay.begin(),bloomDay.end());
        int h = *max_element(bloomDay.begin(),bloomDay.end());

        while(l<=h){
            int mid = l + (h-l)/2;
            if(pos(mid,bloomDay,m,k)){
                ans = mid;
                h = mid-1;
            }else{
                l = mid+1;
            }
        }

        return ans;
        
    }
};