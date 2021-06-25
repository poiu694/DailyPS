#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<vector<int>> A;
vector<vector<int>> B;

void init(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void input(){
    cin >> N >> M;

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> A[i][j];      
        }
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> B[i][j];      
        }
    }
}

void solve(){
    int cnt = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(A[i][j] & B[i][j] == 1){
                cnt++;
            }
        }
    }

    if(cnt == 1){
        
    }
}

int main(){
    init();
    input();
    solve();
}