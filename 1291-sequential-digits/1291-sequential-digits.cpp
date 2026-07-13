class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {

        string digits = "123456789";

        vector<int> res;

        int min = to_string(low).size();
        int max = to_string(high).size();

        for(int len=min;len<=max;len++){
            for(int start=0;start+len<=9;start++){
                int num = stoi(digits.substr(start,len));
                if(num<=high && num>=low){
                    res.push_back(num);
                }

            }
        }
        return res;
    }
};