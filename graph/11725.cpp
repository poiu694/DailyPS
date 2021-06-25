#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> v[100001];
int parent[100001] = {0};
bool visited[100001] = {false};

void input(){
    int a, b;
    cin >> N;

    for(int i=0; i<N; i++){
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    
}

void dfs(int node){
    visited[node] = true; // 방문처리

    for(int i=0; i<v[node].size(); i++){
    	if(visited[v[node][i]] == false){
	        parent[v[node][i]] = node; // v[node] 에서 연결되어있는 자식들은 node를 부모로 갖는다
	        dfs(v[node][i]);
    	}
    }
}

void solve(){
	dfs(1);
	
    for(int i=2; i<=N; i++){
        cout << parent[i] << "\n";
    }
}

int main(){
	input();
	solve();
}