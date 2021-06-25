#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

int T, N, M;
int inDegree[501];
vector<int> tree[501];
vector<int> list;
queue<int> q;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void toFirst(){
    for(int i=0; i<501; i++){
        tree[i].clear();
    }
    memset(inDegree, 0, sizeof(inDegree));
    list.clear();
}

// 위상 정렬
void solve() {
    // inDegree가 0인 팀을 먼저 Q에 담기.
    for(int i=1; i<=list.size(); i++){
        if(inDegree[i] == 0){
            q.push(list[i]);
        }
    }

    while(!q.empty()){
        int now = q.front();
        q.pop();

        cout << now << " ";
        for(int i=0; i<tree[now].size(); i++){
            int next = tree[now][i];
            
            inDegree[next]--;
            if(inDegree[next] == 0){
                q.push(next);
            }
        }
    }

    cout << '\n';
}

void input() {
    cin >> T;

    while(T--){  
        toFirst();      
        cin >> N;
        
        // 작년 순위
        int temp;
        for(int i=0; i<N; i++){
            cin >> temp;
            list.push_back(temp);
        }

        // 바뀐 상대적 그래프
        cin >> M;
        for(int i=0; i<M; i++){
            int node, child;
            cin >> node >> child;

            inDegree[child]++;
        }

        solve();
    }
}

int main() {
    init();
    input();
    solve();
}