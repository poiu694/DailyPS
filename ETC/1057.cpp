#include <iostream>

using namespace std;

void fastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void solve(){
    int N, a, b;
    cin >> N >> a >> b;

    int cnt = 0;
    while(true){
        if(a == b){
            break;
        }

        cnt++;
        a /= 2;
        b /= 2;
    }

    cout << cnt;
}

int main(){
    fastIO();
    solve();
}