// Version 1. DP
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

// Version 2. Dijkstra
#include <cstring>
#include <vector>
#include <cmath>
#include <queue>
#include <climits>

using namespace std;
using pii = pair<int, int>;

struct Info {
	int alp;
	int cop;
    int time;
};

struct compare {
	bool operator()(const Info& info1, const Info& info2) {
        if (info1.time == info2.time) {
            if (info1.alp == info2.alp) {
                return (info1.cop < info2.cop);
            }
            return (info1.alp < info2.alp);
        }
		return info1.time > info2.time;
	}
};

bool    isCanSolveProblem(pii cur, pii req) {
    return (cur.first >= req.first && cur.second >= req.second);
}

vector<vector<int>>    dijkstra(int alp, int cop, int maxAlp, int maxCop, vector<vector<int>> problems) {
    vector<vector<int>> dist(maxAlp * 5, vector<int>(maxCop * 5, INT_MAX));
    priority_queue<Info, vector<Info>, compare> pq;
    
    pq.push({ alp, cop, 0 });
    dist[alp][cop] = 0;
    while (!pq.empty()) {
        Info current = pq.top();
        pq.pop();
        
        if (isCanSolveProblem({ current.alp, current.cop }, { maxAlp, maxCop })) {
            break ;
        }
        if (current.alp < maxAlp && dist[current.alp][current.cop] + 1 < dist[current.alp + 1][current.cop]) {
            dist[current.alp + 1][current.cop] = dist[current.alp][current.cop] + 1;
            pq.push({ current.alp + 1, current.cop, dist[current.alp][current.cop] + 1 });
        }
        if (current.cop < maxCop && dist[current.alp][current.cop] + 1 < dist[current.alp][current.cop + 1]) {
            dist[current.alp][current.cop + 1] = dist[current.alp][current.cop] + 1;
            pq.push({ current.alp, current.cop + 1, dist[current.alp][current.cop] + 1 });
        }
        for (vector<int> problem: problems) {
            if (isCanSolveProblem({ current.alp, current.cop }, { problem[0], problem[1] })) {
                int nextI = current.alp + problem[2] > maxAlp ? maxAlp : current.alp + problem[2];
                int nextJ = current.cop + problem[3] > maxCop ? maxCop : current.cop + problem[3];
                if (dist[nextI][nextJ] > dist[current.alp][current.cop] + problem[4]) {
                    dist[nextI][nextJ] = dist[current.alp][current.cop] + problem[4];
                    pq.push({
                        nextI, nextJ, dist[current.alp][current.cop] + problem[4]
                    });
                }
                
            }
        }
    }
    return (dist);
}

int solution(int alp, int cop, vector<vector<int>> problems) {
    int maxAlp;
    int maxCop;
    vector<vector<int>> dist;
    
    maxAlp = alp;
    maxCop = cop;
    for (vector<int> problem: problems) {
        maxAlp = max(maxAlp, problem[0]);
        maxCop = max(maxCop, problem[1]);
    }
    dist = dijkstra(alp, cop, maxAlp, maxCop, problems);
    return (dist[maxAlp][maxCop]);
}