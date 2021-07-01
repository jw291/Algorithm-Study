//경우의 수를 물어보니 DFS
//일단, 일반적으로 가지는 두가지로 뻗는다.
//두가지로 왼쪽가지와 오른쪽가지에 무엇 차이를 둘 것인가, 무슨 기준으로 뻗어나가게 할 것인가가 중요하다
//DFS는 결국 root부터 시작하는데, 정답 중 배열의 중간부터 나온 답이 있다?
//한쪽 가지는 Level은 증가시켰지만 한쪽가지는 sum은 유지시켰다는 의미.
//이 문제는 위의 모두에 해당돼서 가지가 세개여야한다.

//L로 인덱스를 가리킬 수 있음
//스스로 해결!

//path보면 배열 안에 모든 경우의 수에 값을 넣고
//결국에 12가 나오면 path를 출력함

#include <iostream>
int N,M;
int a[11], path[11];
int cnt = 0;
//int flag = false;
/*
void DFS(int L, int res){//L이 곧 인덱스를 가리킴
    if(res > M) return;
    else if(res == M){
        cnt++;//걍 카운트 0이면 -1
        //flag = true;
        for(int i = 1; i < L; i++) printf("%d ",path[i]);
        puts("");
        return;
    }
    
    if(L == N+1) return;
    else{
        //path 1
        path[L] = a[L];
        DFS(L+1,res + a[L]);
        //path 3
        path[L] = -a[L];
        DFS(L+1,res - a[L]);
        //path 2
        path[L] = 0;
        DFS(L+1,res);
    }
}*/

//선생님은 return안함
void DFS(int L, int res){
    if(L == N+1) {
        if(res == M){
            cnt++;//걍 카운트 0이면 -1
            //flag = true;
            for(int i = 1; i < L; i++) printf("%d ",path[i]);
            puts("");
        }
    }
    else{
        //path 1
        path[L] = a[L];
        DFS(L+1,res + a[L]);
        //path 3
        path[L] = -a[L];
        DFS(L+1,res - a[L]);
        //path 2
        path[L] = 0;
        DFS(L+1,res);
    }
}

int main() {
    int i;
    
    scanf("%d %d",&N,&M);
    for (i = 1; i <= N; i++) {
        scanf("%d",&a[i]);
    }
    
    DFS(1,0);
    
    if(cnt == 0) printf("%d",-1);
    else printf("%d",cnt);
    return 0;
}
