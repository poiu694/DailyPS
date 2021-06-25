#include <iostream>
#include <cstring>
#include <stack>

using namespace std;

string str1, str2, str3;
string LCS;
int dp[101][101][101];
stack<char> st;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void input() {
    cin >> str1 >> str2 >> str3;
}

//LCS
void solve() {
    str1 = '0' + str1;
    str2 = '0' + str2;
    str3 = '0' + str3;

    int len1 = str1.length();
    int len2 = str2.length();
    int len3 = str3.length();

    // make LCS DP 
    for (int i = 0; i < len1; i++) {
        for (int j = 0; j < len2; j++) {
            for (int k = 0; k < len3; k++) {
                if (i == 0 || j == 0 || k == 0) {
                    dp[i][j][k] = 0;
                }
                else {
                    if (str1[i] == str2[j] && str2[j] ==  str3[k]) {
                        dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
                    }
                    else {
                        int temp = (dp[i - 1][j][k] > dp[i][j - 1][k]) ? dp[i - 1][j][k] : dp[i][j - 1][k];
                        int max = (temp > dp[i][j][k - 1]) ? temp : dp[i][j][k - 1];
                        
                        dp[i][j][k] = max;
                    }
                }
            }
        }
    }

    // find LCS_Sequence
    len1--; len2--; len3--;
    while (dp[len1][len2][len3] != 0) {
        if (dp[len1 - 1][len2][len3] == dp[len1][len2][len3]) {
            len1--;
        }
        else if (dp[len1][len2 - 1][len3] == dp[len1][len2][len3]) {
            len2--;
        }
        else if (dp[len1][len2][len3 - 1] == dp[len1][len2][len3]) {
            len3--;
        }
        else {
            st.push(str1[len1]);
            len1--; len2--; len3--;
        }
    }

    while (!st.empty()) {
        LCS = LCS + st.top();
        st.pop();
    }

    cout << LCS.length();
}

int main() {
    init();
    input();
    solve();
}