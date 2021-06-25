#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, K, num;
int answer = 0; 
vector<int> money;

void solve(){
    sort(money.begin(), money.end(), greater<int>());

    int rest = K;
    for(int i=0; i<money.size(); i++){
        //종료 조건
        if(rest == 0){
            break;
        }

        if(rest / money[i] != 0){
            answer += rest / money[i];
            rest = rest % money[i];
        }
    }

    cout << answer;
}

void input(){
    cin >> N >> K;

    for(int i=0; i<N; i++){
    	cin >> num;
    	money.push_back(num);
    }
}

int main(){
    input();
    solve();
}