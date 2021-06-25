#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


void fastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void solve(){
    int N, Q;
    cin >> N >> Q;

    int prefixSum[N+1];
    vector<int> list(N);

    int temp;
    for(int i=0; i<N; i++){
        cin >> list[i];
    }

    sort(list.begin(), list.end());
    prefixSum[0] = list[0];
    for(int i=1; i<N; i++){
        prefixSum[i] = prefixSum[i-1] + list[i];
    }

    int L, B;
    while(Q--){
        cin >> L >> B;

        cout << prefixSum[B] - prefixSum[L] << '\n';
    }

}

int main(){
    fastIO();
    solve();
}