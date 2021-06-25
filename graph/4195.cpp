#include <iostream>

using namespace std;

int T, N;

void fastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void init(){
    cin >> N;

    string a, b;
    for(int i=0; i<N; i++){
        cin >> a >> b;
        cout << a << " " << b << '\n'; 
    }
}

void solve(){
    cin >> T;

    while(T--){
        init();
    }
}

int main(){
    fastIO();
    solve();
}