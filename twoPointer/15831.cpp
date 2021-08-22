#include <iostream>

using namespace std;

void fastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void solve(){
    string target;
    int N, B, W;
    cin >> N >> B >> W >> target;

    int l = 0;
    int r = 0;
    
    int whiteCnt = 0;
    int blackCnt = 0;
    int answer = 0;
    while(r != N + 1) {
        if(whiteCnt >= W and blackCnt <= B) {
            answer = answer > r - l ? answer : r - l;
            
            if(target[r++] == 'W') whiteCnt++;
            else blackCnt++;
        } else if(whiteCnt < W) {
            if(target[r++] == 'W') whiteCnt++;
            else blackCnt++;
        } else if(blackCnt > B) {
            if(target[l++] == 'W') whiteCnt--;
            else blackCnt--;
        }
    }
    cout << answer;
}

int main(){
    fastIO();
    solve();
}
