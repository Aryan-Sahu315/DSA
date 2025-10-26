class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        const int m = primes.size();
        vector<int> dp(n , 0), idx(m, 0);
        vector<long long> nextMultiple(m);
        ++dp[0];
        for (int i = 0; i < m; ++i) nextMultiple[i] = primes[i];
        for (int i = 1; i < n; ++i) {
            long long nextUgly = *min_element(nextMultiple.begin(), nextMultiple.end());
            dp[i] = nextUgly;
            for (int j = 0; j < m; ++j) {
                if (nextUgly == nextMultiple[j]) nextMultiple[j] = (long long)dp[++idx[j]] * primes[j];
            }
        }
        return dp[n - 1];
    }
};