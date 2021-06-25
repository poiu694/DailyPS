#include <iostream>

using namespace std;

int N;

struct Node{
    char data;
    char leftChild;
    char rightChild;
} tree[27];

void preOrder(char node){
    if(node == '.'){
        return;
    }

    cout << node;
    preOrder(tree[node-'A'].leftChild);
    preOrder(tree[node-'A'].rightChild);
}

void inOrder(char node){
    if(node == '.'){
        return;
    }
    
    inOrder(tree[node-'A'].leftChild);
    cout << node;
    inOrder(tree[node-'A'].rightChild);
}

void postOrder(char node){
    if(node == '.'){
        return;
    }
    
    postOrder(tree[node-'A'].leftChild);
    postOrder(tree[node-'A'].rightChild);
    cout << node;
}

void input(){
    cin >> N;

    char now, left, right;
    for(int i=0; i<N; i++){
		cin >> now >> left >> right;
		
	    tree[now-'A'].leftChild = left;
	    tree[now-'A'].rightChild = right;
    }

}

void solve(){
    input();
    preOrder('A');
    cout << "\n";
    inOrder('A');
    cout << "\n";
    postOrder('A');
}

int main(){
    solve();
}