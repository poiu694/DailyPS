#include <iostream>

using namespace std;

int E, S, M;

void init(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void input(){
    cin >> E >> S >> M;
}

// 문제에서 최댓값이 7980번임을 알려주었다.
// 1씩 증가시켜서 7980번 가도 충분히 시간 안에 들어올 수 있다.
void solve(){
    int cnt = 1; // 1 1 1인 경우

    int _E = 1;
    int _S = 1;
    int _M = 1;
    for(; cnt<=7980; cnt++){
        if(E == _E && S == _S && M == _M){
            cout << cnt;
            return;
        }
        _E++; _S++; _M++; // 1년이 지났당

        if(_E > 15){
            _E = 1;
            continue;
        }

        if(_S > 28){
            _S = 1;
            continue;
        }

        if(_M > 19){
            _M = 1;
            continue;
        }

    }
}

int main(){
    init();
    input();
    solve();
}