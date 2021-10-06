#include <string>
#include <vector>
#include <cstring>
#include <limits.h>
#include <cmath>

using namespace std;

vector<int> graph[101];
bool        visited[101];

void go(int n, int a, int b, int now) {
    for (int next : graph[now]) {
        if (visited[next]) continue;
        if (a == now && b == next) continue;
        if (a == next && b == now) continue;
        
        visited[next] = true;
        go(n, a, b, next);
    }
}

int solution(int n, vector<vector<int>> wires) {
    int answer = INT_MAX;
    for (int i=0; i<wires.size(); i++) {
        int a = wires[i][0];
        int b = wires[i][1];
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    for (int i=0; i<wires.size(); i++) {
        int a = wires[i][0];
        int b = wires[i][1];
        memset(visited, false, sizeof(visited));
        for (int j=1; j<=n; j++) {
            if (a == j || b == j) continue ;
            else {
                visited[j] = true;
                go(n, a, b, j);
                break ;
            }
        }
        
        int cnt = 0;
        for (int j=1; j<=n; j++)
            if (visited[j]) cnt++;
        answer = min(answer, abs(n - cnt - cnt));
    }
    return answer;
}