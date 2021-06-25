#include <iostream>
#include <vector>

using namespace std;

int N, score, P;
vector<int> list;

void init(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void input(){
    cin >> N >> score >> P;

    int temp;
    for(int i=0; i<N; i++){
        cin >> temp;
        list.push_back(temp);
    }
}

void solve(){
    int rank = 1;

    int pastScore = list[0];
    int cnt = 0;
    for(int i=1; i<N; i++){
        if(score >= list[i]){
            if(pastScore == list[i]){
                cnt++;
                continue;
            }
            if(cnt != 0){
                rank++;
            }else{
                rank += cnt;
            }
        }
    }

    cout << rank;
}

int main(){
    init();
    input();
    solve();
}