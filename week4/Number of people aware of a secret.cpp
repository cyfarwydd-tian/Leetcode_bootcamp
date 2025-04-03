#include <vector>
using namespace std;

class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        const int MOD = 1e9 + 7;
        vector<int> learned(n + 1, 0);
        learned[1] = 1;  // On day 1, one person knows the secret

        for (int day = 2; day <= n; ++day) {
            for (int share_day = max(1, day - forget + 1); share_day <= day - delay; ++share_day) {
                learned[day] = (learned[day] + learned[share_day]) % MOD;
            }
        }

        // Sum up the number of people who still remember the secret on day n
        int result = 0;
        for (int day = n - forget + 1; day <= n; ++day) {
            result = (result + learned[day]) % MOD;
        }

        return result;
    }
};
