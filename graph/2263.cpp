#include <iostream>

using namespace std;

int N;
int preOrder[100001];
int inOrder[100001];
int postOrder[100001];
int leftArea[26], rightArea[26];

void init(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void input(){
    cin >> N;
    
    for(int i=0; i<N; i++){
        cin >> inOrder[i];
    }

    for(int j=0; j<N; j++){
        cin >> postOrder[j];
    }
}

void solve(){
    //postOrder's Last value is Root Node
    preOrder[0] = postOrder[N-1];

    bool flag = false;
    for(int i=0; i<N; i++){
        if(preOrder[0] == inOrder[i]){
            flag = true;;
        }else{
            if(flag){
                rightArea[i] = inOrder[i];
            }else{
               leftArea[i] = inOrder[i];
            }
        }
    }
}

int main(){
    init();
    input();
}