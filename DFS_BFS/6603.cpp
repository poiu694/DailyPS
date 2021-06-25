#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> number;
int lotto[7];

void init(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void dfs(int node, int depth){
	if(depth == 6){
        for(int i=0; i<6; i++){
            cout << lotto[i] << " ";
        }
        cout << '\n';
        return;
    }

    for(int i=node; i<N; i++){
        lotto[depth] = number[i];
        dfs(i+1, depth+1);
    }
}

void solve(){
    dfs(0, 0);
    number.clear();
    cout << '\n';
}

void input(){
    int temp;

    while(true){
        cin >> N;

        // 입력 종료
        if(N == 0){
            break;
        }
        
        for(int i=0; i<N; i++){
            cin >> temp;

            number.push_back(temp);
        }

        solve();
    }
}

int main(){
    init();
    input();
}
