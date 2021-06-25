#include <iostream>

using namespace std;

int answer = -1;
long long yoon, dong;

void init(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void input(){
    cin >> yoon >> dong;
}

void dfs(int depth, long long y, long long d, int ycnt, int dcnt){
    if(yoon == y && dong == d){
        answer = min(answer, ycnt);
    }

    if(y > yoon || d > dong){
        return;
    }

    dfs(depth+1, y + depth, d, ycnt + 1, dcnt);
    dfs(depth+1, y, d + depth, ycnt, dcnt + 1);
}

void solve(){
    dfs(0, 0, 0, 0, 0);

    cout << answer;
}

int main(){
    init();
    input();
    solve();
}