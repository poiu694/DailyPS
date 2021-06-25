#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
vector<string> list;
vector<string> goal;

void fastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void solve(){
    cin >> N;

    string temp;
    for(int i=0; i<N; i++){
        cin >> temp;
        list.push_back(temp);
    }

    for(int i=0; i<N-1; i++){
        cin >> temp;
        goal.push_back(temp);
    }

    sort(list.begin(), list.end());
    sort(goal.begin(), goal.end());

    string answer = list[list.size() - 1];
    for(int i=0; i<goal.size(); i++){
        if(list[i] == goal[i]){
            continue;
        }else{
            answer = list[i];
            break;
        }
    }

    cout << answer;
}

int main(){
    fastIO();
    solve();
}