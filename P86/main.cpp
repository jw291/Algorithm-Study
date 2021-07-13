//서로다른 n개의 숫자중
//r개의 숫자로 뽑아내는 방법(모든 경우의 수)
//for문 가지로 뻗어나가는 방식
//한다 안한다의 방식 블로그에 기록하기
#include <iostream>

using namespace std;
int n,r;
int ch[20];

void DFS(int s, int L){
    if(L==r){
        for(int j = 0; j < L; j++){
            cout << ch[j] << " ";
        }
        cout << endl;
    }
    else{
        for(int i = s; i < n; i++){
            ch[L] = i;
            DFS(i+1, L+1);
        }
    }
}

int main() {
    cin>>n>>r;
    DFS(0,0);
    return 0;
}
