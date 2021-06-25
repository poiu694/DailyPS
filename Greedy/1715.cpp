#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> cardList;

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
        cardList.push_back(temp);
    }
}

void solve(){
    // 더하기 전에 항상 오름차순으로 정렬하고 맨 앞 두개를 더한다.
    // A+B = C, C를 cardList에 넣어주고 빌 때까지 반복.

    int sum = 0;
    vector<int>::iterator iter;
    while(!cardList.empty()){
        sort(cardList.begin(), cardList.end());
        iter = cardList.begin();
        int C = cardList[0] + cardList[1];
        sum += C;
        
        cardList.erase(iter, iter+2);
        cardList.push_back(C);
    }

    cout << sum;
}

int main(){
    init();
    input();
    solve();
}
