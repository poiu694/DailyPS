#include <iostream>

using namespace std;

int N, K;

void init(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void input(){
    cin >> N >> K;
}

void solve(){
    cout << "<";

    int cnt = N;

    while(cnt != N){
        int temp = K % N;
        cnt++;
        K += K;

        cout << temp << ", ";
    }

    cout << ">";
}

int main(){
    init();
    input();
    solve();
}
