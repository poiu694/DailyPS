#include <iostream>
#include <vector>

using namespace std;

void fastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

// BruteForce -> O(NK), N<=3e5, K<=N -> TLE
// Need O(N) or O(NlogN) solve
// list[i] -> list[i+1] -> list[i+2] ... list[i+k] Check
// 
void solve(){
    int N, K;
    cin >> N >> K;
    
    vector<string> list(N+1);
    for(int i=0; i<N; i++){
        cin >> list[i];
    }

    // O(NK)
    int cnt = 0;
    for(int i=0; i<N; i++){
        for(int j=i+1; j<=K; j++){
            if(list[i].length() == list[j].length()){
                cnt++;
            }
        }
    }

    cout << cnt;
}

int main(){
    fastIO();
    solve();
}
