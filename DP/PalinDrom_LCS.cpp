#include <iostream>
#include <string.h>

using namespace std;

int dp[1001][1001]; // LCS DP
string target;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void input() {
    cin >> target;
}

int LCS(string s) {
    string s1 = s;
    string s2 = s;
    reverse(s2.begin(), s2.end());

    s1 = '0' + s1; // for LCS
    s2 = '0' + s2; // for LCS


    for (int i = 0; i < s1.length(); i++) {
        for (int j = 0; j < s2.length(); j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
                continue;
            }

            if (s1[i] == s2[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[s1.length() - 1][s2.length() - 1];
}

// LCS를 이용
// ans = target.length() + LCS.length()
void solve() {
    int LCS_length = LCS(target);

    cout << target.length() + LCS_length;
}

int main() {
    init();
    input();
    solve();
}