#include <iostream>

using namespace std;

char map[501][501];

void fastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void solve(){
    int N;
    cin >> N;

    for(int i=0; i<N; i++){
        cin >> map[i];
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cout << map[i][j] << ' ';
        }
        cout << '\n';
    }
}

int main(){
    fastIO();
    solve();
}