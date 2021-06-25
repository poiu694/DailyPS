#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> list;

void solve(int start, int end){
    int sum = 0;

    for(int i=start-1; i<end; i++){
        sum += list[i];
    }
    
    cout << sum << '\n';
}

void input(){
    cin >> N >> M;

    int num;
    for(int i=0; i<N; i++){
        cin >> num;
        list.push_back(num);
    }

    int start, end;
    for(int i=0; i<M; i++){
        cin >> start >> end;
        solve(start, end);
    }
}

int main(){
    input();
}