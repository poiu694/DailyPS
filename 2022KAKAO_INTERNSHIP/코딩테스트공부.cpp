#include <cstring>
#include <vector>
#include <cmath>

using namespace std;
using pii = pair<int, int>;

bool isCanSolveProblem(pii current, pii request) {
    return (current.first >= request.first &&
                current.second >= request.second);
}

int solution(int alp, int cop, vector<vector<int>> problems) {
    int i, j;
    int nextI, nextJ;
    int dp[151][151];
    int maxAlp, maxCop;

    maxAlp = alp;
    maxCop = cop;
    for (vector<int> problem: problems) {
        maxAlp = max(maxAlp, problem[0]);
        maxCop = max(maxCop, problem[1]);
    }
    memset(dp, 1, sizeof(dp));
    dp[alp][cop] = 0;
    for (i = alp; i<= maxAlp; i++) {
        for (j = cop; j<= maxCop; j++) {
            if (i < maxAlp) {
                dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + 1);
            }
            if (j < maxCop) {
                dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + 1);
            }
            for (vector<int> problem: problems) {
                if (isCanSolveProblem({ i, j }, { problem[0], problem[1] })) {
                    nextI = i + problem[2] > maxAlp ?  maxAlp : i + problem[2];
                    nextJ = j + problem[3] > maxCop ?  maxCop : j + problem[3]; 
                    dp[nextI][nextJ] =
                        min(dp[nextI][nextJ], dp[i][j] + problem[4]);
                }
            }
        }
    }
    return (dp[maxAlp][maxCop]);
}