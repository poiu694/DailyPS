#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int N, K;
int result = 0;
vector<pair<int,int>> item;
bool visited[101] = {false, };

void init(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void input(){
    cin >> N >> K;

    int a, b;
    for(int i=0; i<N; i++){
        cin >> a >> b;

        item.push_back({a, b});
    }
}

void dfs(int nowNode, int nowWeight, int cost){
    // 최대치를 갖고 있다면
    if(cost > result){
        result = cost;
    }

    visited[nowNode] = true; // 방문처리

    // 탐색
    for(int i=0; i<N; i++){
        int weight = item[i].first;
        int value = item[i].second;
        int node = i;

        if(!visited[node] && (nowWeight + weight) <= K ){
            dfs(node, nowWeight + weight, value + cost);
        }
    }
}

int main(){
    init();
    input();
    for(int i=0; i<N; i++){
        memset(visited, false, sizeof(visited));
    	dfs(i, 0, 0);
    }
    cout << result;
}