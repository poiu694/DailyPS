#include <iostream>
#include <queue>

using namespace std;
int loca[3];
int N,K;
bool Check[100001]={false};
int Num[100001]={0};

void makeLoca(int N){
    loca[0]=N-1;
    loca[1]=N+1;
    loca[2]=N*2;
}

int bfs(int N){

    queue<int> Q;
    Q.push(N);

    while(!Q.empty()){
        int node = Q.front();
        Q.pop();
        Check[node]=true;

        makeLoca(node);

        if(node==K)
            {
                break;
            }

        for(int i=0; i<3; i++){
            if(loca[i]<0) continue;
            if((loca[i]<=1000000) && !Check[loca[i]])
            {
                Q.push(loca[i]);
                Check[loca[i]]=true;
                Num[loca[i]]=Num[node]+1;
            } 
        }
    }

    
}

int main() {
   // your code goes here
    int result;

    cin >> N >> K;

    if(K<N)
        result=N-K;
    else if (K==N)
        result=0;
   else {
        bfs(N);
        result=Num[K];
    }

    cout << result;

   return 0;
}