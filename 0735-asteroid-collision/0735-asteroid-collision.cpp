class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {

        //brute force
        /*bool collision = true;

        while (collision) {

            collision = false;

            for (int i = 0; i < asteroids.size() - 1; i++) {

                // Collision condition
                if (asteroids[i] > 0 && asteroids[i + 1] < 0) {

                    collision = true;

                    // Left asteroid is smaller
                    if (abs(asteroids[i]) < abs(asteroids[i + 1])) {
                        asteroids.erase(asteroids.begin() + i);
                    }

                    // Right asteroid is smaller
                    else if (abs(asteroids[i]) > abs(asteroids[i + 1])) {
                        asteroids.erase(asteroids.begin() + i + 1);
                    }

                    // Both are equal
                    else {
                        asteroids.erase(asteroids.begin() + i,
                                        asteroids.begin() + i + 2);
                    }

                    break;  // Start scanning again
                }
            }
        }

        return asteroids;*/


        //optimised logic

        stack<int> st;
        for(int num : asteroids){
            bool destroyed = false;
            while(!st.empty() && st.top()>0 && num<0){
                if(abs(st.top())<abs(num)){//top asteroid destroyed
                    st.pop();
                }else if(abs(st.top())==abs(num)){ //both asteroid destroyed
                    st.pop();
                    destroyed=true;
                    break;
                }else{ //curr asteroid destroyed
                    destroyed=true;
                    break;

                }
            }
            if(!destroyed){ //push curr asteroid only if it survived
                st.push(num);
            }
        }

        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }    
        reverse(ans.begin(),ans.end());
        return ans;       
    }
};