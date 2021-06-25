#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

vector<pair<int,int>> v[100001];
bool visited[100001] = {false};
int N, maxNode;
int result = 0;

void init(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void input(){
    cin >> N;

    for(int i=0; i<N; i++){
        int node;
        int nextNode, value;

        cin >> node;
        while(true){
            cin >> nextNode;
            if(nextNode == -1){
                break;
            }
			cin >> value;
			
            v[node].push_back({nextNode, value});
            v[nextNode].push_back({node, value});
        }
    }
}

void dfs(int node, int sum){
	//방문이 끝났을 때
    if(visited[node]){
    	return;
    }
	visited[node] = true; // 방문처리
	
    if(result < sum){
    	maxNode = node;
        result = sum;
    }
	
    for(int i=0; i<v[node].size(); i++){
    	dfs(v[node][i].first, sum + v[node][i].second);
    }
}

void solve(){
	dfs(1, 0);
	memset(visited, false, sizeof(visited));
	result = 0;
	dfs(maxNode, 0);
	cout << result;
}

int main(){
	init();
    input();
    solve();
}