#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

queue<int> q;
vector<int> check;
vector<int> graph[1001];
int N, M, V;

bool find(vector<int> vec, int num){
    bool b1 = false;

    for(int i=0; i<vec.size(); i++){
        if(vec[i] == num){
            b1 = true;
            break;
        }
    }
    return b1;
}

void BFS(queue<int> &q){
	if(q.empty()){
		return;	
	}
	
	cout << q.front() << " ";
	int node = q.front();
	q.pop();
	
 	for(int i=0; i<graph[node].size(); i++){
		if(!find(check, graph[node][i])){
			check.push_back(graph[node][i]);
			q.push(graph[node][i]);
		}
 	}
 
	BFS(q);
}

void sort(){
    for(int i=0; i<N; i++){
        sort(graph[i].begin(), graph[i].end());
    }
}

void input(){
    int a, b;

    cin >> N >> M >> V;

    for(int i=0; i<M; i++){
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    q.push(V);
    check.push_back(V);
}


int main(){
	input();
    sort();
	BFS(q);
}