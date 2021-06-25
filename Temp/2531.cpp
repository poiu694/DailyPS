#include <iostream>
#include <vector>

using namespace std;

void fastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void solve(){
    int N, D, K, C;
    cin >> N >> D >> K >> C;
    
    vector<int> list(N);
    bool visited[3001]; 
    for(int i=0; i<N; i++){
        cin >> list[i];
    }

    int ans = -1;
    visited[C] = true; // Event
    for(int i=0; i<N; i++){
        int pt = i+1;
        visited[i] = true;
        visited[pt] = true;

        int repCnt = 2; // i, i+1
        while(repCtn != K){
            visited[++pt] = true;
            repCnt++;
        }

        int tempCnt = 0;
        for(int j=1; j<=D; j++){
            if(visited[j]){
                tempCnt++;
            }
        }

        ans = ans > tempCnt ? ans : tempCnt;
    }

    cout << ans;
}

int main(){
    fastIO();
    solve();
}