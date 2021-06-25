#include <iostream>

using namespace std;

int N, target;
vector<int> list;

void init(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void input(){
    cin >> N;
    list.resize(N);

    for(int i=0; i<N; i++){
        cin >> list[i];
    }

    cin >> target;
}

void solve(){
    for(int i=0; i<list.size(); i++){
        cout << list[i] << " ";
    }
}

int main(){
    init();
    input();
    solve();
}