//체크를 안해서 싸이크 도는 것 빼고는
//인접행렬과 dfs을 융합하여 생각하는 것은 성공했음

#include <iostream>

int map[21][21];
int N,M;
int cnt = 0;
int ch[30];
// 이게 없으면 cycle생김
//방문한 노드 체크를 해야함

void DFS(int v){
    int i;
    if(v == N) {
        cnt++;
    }else{
    
        for(i = 1; i <= N; i++){
            if(map[v][i] == 1 && ch[i] == 0){ //방문하지 않은 노드로 가겠다.
                ch[i] = 1;
                DFS(i);
                ch[i] = 0; // 일 끝나면 0으로 돌려놓음
            }
        }
    }
}

int main() {
    int a,b;
    int i;
    scanf("%d %d",&N,&M);
    
    for(i = 1; i <= M; i++){
        scanf("%d %d",&a,&b);
        map[a][b] = 1;
    }
    ch[1] = 1;//1에서 시작 체크
    
    DFS(1);
    
    printf("%d",cnt);
    return 0;
}
/*
5 9
1 2
1 3
1 4
2 1
2 3
2 5
3 4
4 2
4 5
 */
