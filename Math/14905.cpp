#include <iostream>
#include <cstring>

using namespace std;

bool prime[100000001];

void fastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void make_prime(){
    memset(prime, true, sizeof(prime));

    for(int i=2; i*i<100000000; i++){
        if(!prime[i]){
            continue;
        }

        for(int j=i*i; j<=100000000; j+=i){
            prime[j] = false;
        }
    }
}

bool find_prime(int num){
    if(num % 2 == 0){
        return false;
    }

    if(num < 8){
        return false;
    }



    return true;
}

void solve(){
    int num;

    make_prime();
    while(cin >> num){
        if(find_prime(num)){

        }else{
            cout << 
        }
    }
}

int main(){
    fastIO();
    solve();
}