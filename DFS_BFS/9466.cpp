#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int people[100001];
int visited[100001];
bool termProjectPeople[100001];

void fastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void dfs(vector<int> list, int start, int node, bool isFirst){ // flag : isFirst?
    if(start == node && !isFirst){
        for(int i=0; i<list.size(); i++){
            termProjectPeople[list[i]] = true;
        }
        return;
    }
    
    isFirst = false;
    int nextPerson = people[node];
    if(visited[nextPerson] != start && !termProjectPeople[nextPerson]){ // 방문한 적이 있다면 팀이 아니다.
        visited[nextPerson] = start;
        list.push_back(nextPerson);
        dfs(list, start, nextPerson, isFirst);
    }
}

void solve(){
    int T;
    cin >> T;
    while(T--){
    	memset(termProjectPeople, 0, sizeof(termProjectPeople));
    	memset(people, 0, sizeof(people));
    	memset(visited, false, sizeof(visited));
        int N;
        cin >> N;
        
        for(int i=1; i<=N; i++){
            cin >> people[i];

            if(i == people[i]){ // Solo Team
                termProjectPeople[i] = true;
            }
        }

        for(int i=1; i<=N; i++){
            if(!termProjectPeople[people[i]]){ // 중복탐색 방지.
                dfs({people[i]}, i, i, true);
            }
        }

        int cnt = 0;
        for(int i=1; i<=N; i++){
            if(!termProjectPeople[i]){
                cnt++;
            }
        }

        cout << cnt << '\n';
    }
}

int main(){
    fastIO();
    solve();
}