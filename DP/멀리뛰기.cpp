#include <string>
#include <vector>

using namespace std;

const int MOD = 1234567;

long long solution(int n)
{
    long long answer = 0;
    int dp[2001];
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; i++)
    {
        dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
    }
    answer = dp[n] % MOD;
    return answer;
}