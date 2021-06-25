#include <iostream>
#include <queue>

using namespace std;

int N;
priority_queue<int, vector<int>, less<int>> maxQ;

void init(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void input(){
    cin >> N;

    int temp;
    for(int i=0; i<N; i++){
        cin >> temp;
        maxQ.push(temp);
    }
}

void solve(){
    while(!maxQ.empty()){
        cout << maxQ.top() << " ";
        maxQ.pop();
    }
}

int main(){
    init();
    input();
    solve();
}