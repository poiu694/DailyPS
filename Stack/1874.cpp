#include <iostream>
#include <queue>
#include <stack>

using namespace std;

int index = 0;
int N;
bool flag = true;
stack<int> st;
queue<char> out;

void init(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void stack_op(int num){
    //처음 들어왔을 때
    if(st.empty()){
    	int top = 0;
    	
        while(top != num){
            st.push(++index);
            top = st.top();
            out.push('+');
        }
        st.pop();
        out.push('-');

        return;
    }
	
	//들어온 값이 top과 같을 때
	if(st.top() == num){
		st.pop();
		out.push('-');
	}
    //들어온 값이 top보다 작을 때
    else if(st.top() > num){
    	//실패 조건
    	if(st.top() < index){
    		flag = false;
    		return;
    	}
        int repeat = index - num;

        for(int i=0; i<repeat; i++){
            st.pop();
            out.push('-');
        }
    }
    //들어온 값이 top보다 클 때
    else if(st.top() < num){
    	//실패 조건
    	if(index > num){
    		flag = false;
    		return;
    	}
    	
        while(st.top() != num){
            st.push(++index);
            out.push('+');
        }
        st.pop();
        out.push('-');
    }
}

void solve(){
    int temp;

    cin >> N;
    for(int i=0; i<N; i++){
        cin >> temp;
        stack_op(temp);
    }
    
    if(flag){
    	while(!out.empty()){
    		cout << out.front() << '\n';
    		out.pop();
    	}
    }else{
    	cout << "NO";
    }
}

int main(){
    init();
    solve();
}