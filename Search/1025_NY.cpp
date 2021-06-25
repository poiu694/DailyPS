#include <iostream>
#include <math.h>

using namespace std;

int N, M; // 가로 세로
int list[N+1][M+1];

void init(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void input(){
    cin >> N >> M;
    
    string str;
    for(int i=0; i<N; i++){
        cin >> str;

        for(int j=0; j<M; j++){
            list[i][j] = (int) (str[j] - '0');
        }
    }
}

bool is_square(int num){
    int root = (int) sqrt(num);

    if(root * root == num){
        return true;
    }else{
        return false;
    }
}

void solve(){
    int num;

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(is_square(list[i][j]){
                if(max < list[i][j]){
                    max = list[i][j];
                }
            }
        }
    }
}

int main(){
    init();
    input();
}
