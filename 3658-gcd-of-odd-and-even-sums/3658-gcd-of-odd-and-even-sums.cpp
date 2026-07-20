class Solution {
public:
    int gcdOfOddEvenSums(int n) {

        int sumodd=0;
        int sumeven=0;
        int i=2;
        int j=1;

        while(n>0){
            sumodd+=j;
            j+=2;
            sumeven+=i;
            i+=2;
            n--;

        }

        return gcd(sumodd,sumeven);

        
    }
};