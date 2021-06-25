#include <iostream>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

int N, M, result;
bool visited[101];
vector<int> tree[101];
queue<pair<int, int>> q;
int sum[101];

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void bfs(int index) {
    q.push({index, 0});
    visited[index] = true;

    while (!q.empty()) {
        int node = q.front().first;
        int value = q.front().second;
        q.pop();

        for (int i = 0; i < tree[node].size(); i++) {
            int nextNode = tree[node][i];
            int nextValue = value + 1;

            if (visited[nextNode]) {
                continue;
            }

            visited[nextNode] = true;
            sum[index] += nextValue;
            q.push({ nextNode, nextValue });
        }
    }
}

void solve() {
    for (int i = 1; i <= N; i++) {
        bfs(i);
        memset(visited, false, sizeof(visited));
    }
    
    result = 1;
    for(int i=1; i<=N; i++){
    	if(sum[result] > sum[i]){
    		result = i;
    	}
    }
    
    cout << result;
}

void input() {
    int a, b;

    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
}

int main() {
    init();
    input();
    solve();
}