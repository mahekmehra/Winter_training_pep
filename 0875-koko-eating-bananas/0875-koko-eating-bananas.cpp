class Solution {
public:

    bool check(int mid,int h,vector<int>& piles){

        for(int x:piles){
            int rem = (x/mid);
            h-=rem;
            if((x%mid)!=0){
                h--;
            }
        }
        return (h<0)? false : true;
    }



    int minEatingSpeed(vector<int>& piles, int h) {

        int n = piles.size();
        sort(piles.begin(),piles.end()); //sort the pile
        int l = 1; //can eat min 1 banana in an hour
        int high = piles[n-1];  //can eat the highest pile in the array in an hour att maximum
        while(l<high){
            int mid = l+(high-l)/2;
            if(check(mid,h,piles)){ //if satisfying condition of eating all bananas in all hours covered
                high = mid;  //keep decreasing h till it becomes false..last h will be the answer
            }else{
                l = mid+1;   // if not answer, check for +1 answer

            }
        }

        return l;
        
    }
};