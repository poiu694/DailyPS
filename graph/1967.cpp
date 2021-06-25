#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int N, endNode;
int result = 0;
vector<pair<int,int>> tree[10001];
bool visited[10001] = {false, };

void init(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void input(){
    int node, child, value;    
    cin >> N;

    for(int i=1; i<N; i++){
        cin >> node >> child >> value;

        tree[node].push_back({child, value});
        tree[child].push_back({node, value});
    }
}

void dfs(int node, int sum){
    // 탐색 종료
    if(visited[node]){
        return;
    }

    // 현재까지가 제일 긴 지름일 때
    if(sum > result){
        result = sum;
        endNode = node;
    }

    // 방문처리
    visited[node] = true;

    // 탐색
    for(int i=0; i<tree[node].size(); i++){
        dfs(tree[node][i].first, tree[node][i].second + sum); 
    }
}

int main(){
    init();
    input();
    dfs(1, 0);
    memset(visited, false, sizeof(visited));
    dfs(endNode, 0);
    cout << result;
}