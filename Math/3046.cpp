#include <iostream>

using namespace std;

void fastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void solve(){
    int N, S;
    cin >> N >> S;

    cout << - N + (2*S);
}

int main(){
    fastIO();
    solve();
}