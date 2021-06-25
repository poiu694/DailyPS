#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> list;

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
        list.push_back(temp);
    }
}

int firstGrade(int now, int index){
    if(now < 0 || now > 20){
        return 0;
    }

    if(index == N){
        return 1;
    }

    firstGrade(now + list[index], index + 1);
    firstGrade(now - list[index], index + 1);
}

void solve(){
    cout << firstGrade(0, 0);
}

int main(){
    init();
    input():
    solve();
}