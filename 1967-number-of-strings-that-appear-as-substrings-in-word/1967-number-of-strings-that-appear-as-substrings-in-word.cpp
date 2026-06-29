class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {

        int n = word.size();
        int cnt = 0;

        for (string x : patterns) {
            int sz = x.size();

            if (sz > n) continue;

            bool found = false;

            for (int start = 0; start <= n - sz; start++) {
                int i = 0, j = start;

                while (i < sz && j < n && x[i] == word[j]) {
                    i++;
                    j++;
                }

                if (i == sz) {
                    found = true;
                    break;
                }
            }

            if (found) cnt++;
        }

        return cnt;
    }
};