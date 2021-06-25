#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> arr, list;
bool visited[101];

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void input(){
    int N;

    cin >> N;
    for(int i=1; i<=N; i++){
        arr.push_back(i);
    }

    for(int i=0; i<N; i++){
        int temp;
        cin >> temp;

        list.push_back(temp);
    }
}

vector<int> dfs(vector<int> answer, int depth){
    if(depth == N){
        return answer;
    }

    for(int i=0; i<arr.size(); i++){
        for(int j=0; j<list.size(); j++){
            if(arr[i] == list[j] && !visited[arr[i]]){
                answer.push_back(arr[i]);
                visited[arr[i]] = true;
                dfs(answer, depth+1);
            }
        }
    }
}

void solve(){
    vector<int> answer = dfs({}, 0);

    cout << answer.size() << "\n";
    for(int i=0; i<answer.size(); i++){
        cout << answer[i] << '\n';
    }
}

int main(){
    init();
    input();
    solve();
}