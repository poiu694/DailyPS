#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, MID;
priority_queue<int, vector<int>, less<int>> minQ;
priority_queue<int, vector<int>, greater<int>> maxQ;


void init(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void middle(){
    int leftSize = minQ.size(); // MID보다 작은 수들의 크기
    int rightSize = maxQ.size(); // MID보다 큰 수들의 크기

    // MinQ의 원소들이 MaxQ의 원소들보다 많다면
    // MID는 중간값이 아니다. -> MinQ에서 첫번째 값은 MinQ에서 제일 큰 값이고, 이게 곧 MID가 된다.
    // MaxQ의 원소들이 MinQ 원소보다 많다면 반대로 해준다.
    if(leftSize > rightSize){
        maxQ.push(MID);
        leftSize++;
        MID = minQ.top();
        minQ.pop();
    }else if(rightSize > leftSize){
        minQ.push(MID);
        rightSize++;
        MID = maxQ.top();
        maxQ.pop();
    }
}

void input(){
    int num;
    cin >> N;

    for(int i=0; i<N; i++){
        cin >> num;

        // 원소가 1개일 때
        if(i == 0){
            MID = num;
            cout << MID << "\n";
            continue;
        }

        if(MID > num){
            minQ.push(num);
        }else{
            maxQ.push(num);
        }
        middle();

        cout << MID << "\n";
    }
}

int main(){
    init();
    input();
}