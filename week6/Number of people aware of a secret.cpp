#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        const int MOD = 1e9 + 7;
        vector<long long> dp(n + 1); // dp[i]: number of people who learn the secret on day i
        dp[1] = 1;
        long long share = 0;

        for (int day = 2; day <= n; ++day) {
            // Add people who are now able to share the secret
            if (day - delay >= 1) share = (share + dp[day - delay]) % MOD;
            // Remove people who forget the secret today
            if (day - forget >= 1) share = (share - dp[day - forget] + MOD) % MOD;
            dp[day] = share;
        }

        // Sum the number of people who still remember the secret at the end
        long long result = 0;
        for (int day = n - forget + 1; day <= n; ++day) {
            result = (result + dp[day]) % MOD;
        }

        return result;
    }
};

// Example usage
int main() {
    Solution sol;
    cout << sol.peopleAwareOfSecret(6, 2, 4) << endl; // Output: 5
    cout << sol.peopleAwareOfSecret(4, 1, 3) << endl; // Output: 6
    return 0;
}
