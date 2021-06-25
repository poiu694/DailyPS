#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int answer = -1;

void fastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void dfs(vector<int> &list, int now, int idx, int depth, int M){
    if(depth == M){
        answer = max(answer, now);
    }
    now = list[idx] + now;
    dfs(list, now, idx+1, depth+1, M);
    dfs(list, (now/2), idx+2, depth+1, M);
}

void solve(){
    int N, M;
    cin >> N >> M;

    vector<int> list(N+1);
    for(int i=0; i<N; i++){
        cin >> list[i];
    }

    dfs(list, 0, 0, 0, M);
    cout << answer;
}

int main(){
    fastIO();
    solve();
}