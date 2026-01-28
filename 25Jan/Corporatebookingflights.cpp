vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {

        vector<int> pref(n+1,0);
        for(int i=0;i<bookings.size();i++){
            int f = bookings[i][0];
            int l = bookings[i][1];
            int seats = bookings[i][2];

            pref[f]+=seats;
            if(l+1<n+1) pref[l+1] -= seats;
        }

        vector<int> ans;

        for(int i=1;i<n+1;i++){
            pref[i]+=pref[i-1];
            ans.push_back(pref[i]);
        }

        return ans;
        
}

TC - O(N+B)
SC - O(N)