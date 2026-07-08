class Solution {
public:
    const long long MOD = 1e9 + 7;

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {

        vector<int> pos;
        vector<int> digit;

        // Store non-zero digits and their positions
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != '0') {
                pos.push_back(i);
                digit.push_back(s[i] - '0');
            }
        }

        int k = digit.size();

        // powers of 10
        vector<long long> pow10(k + 1, 1);
        for (int i = 1; i <= k; i++)
            pow10[i] = (pow10[i - 1] * 10) % MOD;

        // prefix digit sum
        vector<long long> prefSum(k + 1, 0);

        // prefix concatenated number
        vector<long long> prefNum(k + 1, 0);

        for (int i = 1; i <= k; i++) {
            prefSum[i] = prefSum[i - 1] + digit[i - 1];
            prefNum[i] = (prefNum[i - 1] * 10 + digit[i - 1]) % MOD;
        }

        vector<int> ans;

        for (auto &q : queries) {

            int l = q[0];
            int r = q[1];

            int left = lower_bound(pos.begin(), pos.end(), l) - pos.begin();
            int right = upper_bound(pos.begin(), pos.end(), r) - pos.begin() - 1;

            if (left > right) {
                ans.push_back(0);
                continue;
            }

            int len = right - left + 1;

            long long sum = prefSum[right + 1] - prefSum[left];

            long long x =
                (prefNum[right + 1]
                - prefNum[left] * pow10[len] % MOD
                + MOD) % MOD;

            ans.push_back((x * (sum % MOD)) % MOD);
        }

        return ans;
    }
};