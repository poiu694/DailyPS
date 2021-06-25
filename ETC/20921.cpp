#include <iostream>

using namespace std;

int N, K;

void init(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void solve(){
    cin >> N >> K;

    // 그렇고 그런 사이가 없을 경우
    if(K == 0){
        for(int i=1; i<=N; i++){
            cout << i << '\n';
        }
        return;
    }
}

int main(){
    init();
    solve();
}