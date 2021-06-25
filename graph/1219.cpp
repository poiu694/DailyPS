#include <iostream>
#include <vector>

using namespace std;

void fastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void solve(){
    int N, M, sCity, eCity;
    cin >> N >> M >> sCity >> eCity;

    vector<pair<int, int>> list[101]; // Node - child & value
    int a, b, c;
    for(int i=0; i<M; i++){
        cin >> a >> b >> c;
        list[a].push_back({b,c});
    }
}

int main(){
    fastIO();
    solve();
}