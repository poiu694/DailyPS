#include <iostream>
#include <cstdlib>
#include <cstring>
#include <vector>

using namespace std;

int T; // Test Case
int homeX, homeY;
int festX, festY;
vector<pair<int,int>> util;
bool visited[101] ={false,};
bool flag;

void dfs(int x, int y, int node){
    if(visited[node]){
        return;
    }

    // 종료 조건(페스티벌 위치가 1000보다 작을 때)
    if(abs(festX-x) + abs(festY-y) <= 1000){
        flag = true;
    }else{
        visited[node] = true;
        
        for(int i=0; i<util.size(); i++){
            int dX = abs(util[i].first - x);
            int dY = abs(util[i].second - y);
            
            if(dX + dY <= 1000){
                dfs(util[i].first, util[i].second, i+1);
            }
        }
    }
}

void solve(){
    cin >> T;

    while(T--){
        int n, x, y;
        cin >> n;
        
        util.clear();
        flag = false;
        memset(visited, false, sizeof(visited));

        cin >> homeX >> homeY;
        for(int i=0; i<n; i++){
            cin >> x >> y;
            util.push_back({x,y});
        }
        cin >> festX >> festY;

        dfs(homeX, homeY, 0);
        
        if(flag){
            cout << "happy\n";
        }else{
            cout << "sad\n";
        }
    }
}

int main(){
    solve();
}