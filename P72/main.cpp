//queue를 이용하면 체크 배열이 필요 없음
//그냥 pop시켜버리면 되니까
//잔머리가 좀 필요하네
//아이디어 듣고 코드는 스스로 짬
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
int main() {
    int N,K,i,cnt = 1,x;
    queue<int> Q;
    scanf("%d %d",&N,&K);
    for (i = 1; i <= N; i++) {
        Q.push(i);
    }
    
    while(!Q.empty()){
        //cnt필요 없이 걍
        //for문을 1부터 2까지 돌리면 되네
        //어차피 while안에서 쓰니까 계속 1~2 1~2 1~2이렇게 돌테니까
        if(Q.size() == 1){
            printf("%d",Q.front());
            break;
        }
        
        if(cnt >= K) {
            Q.pop();
            cnt = 1;
        }
        else {
            x = Q.front();
            Q.push(x);
            Q.pop();
            cnt++;
        }
    }
    
    return 0;
}
