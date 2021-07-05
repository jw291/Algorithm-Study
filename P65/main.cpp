//경우의 수. == dfs
#include <iostream>
//거의 다 풀었는데
//row나 col이 0으로 가는 것에 대해서 고민을 많이함
//continue도 활용이 쏠쏠할듯함.
#include <algorithm>

using namespace std;

int map[10][10],ch[10][10];
int cnt = 0;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
void DFS(int row, int col){//상하좌우만 되니까 둘 중 하나만 +1이 돼야함.둘다 +1이면 대각선 이동임
    int i;
    int xx;
    int yy;
    if(row == 7 && col == 7) cnt++;
    else{
        for(i = 0; i < 4; i++){
            xx = row+dx[i];
            yy = col+dy[i];
            if((1 > xx || xx > 7) || (1 > yy || yy > 7)) continue; // 1보다 작고 7보다크면 다시 for문으로
            //1로 초기화해줄 필요가 없네 이렇게하면
            
            if(map[xx][yy] == 0 && ch[xx][yy] == 0){
                ch[xx][yy] = 1;
                DFS(xx,yy);
                ch[xx][yy] = 0;
            }
         }
    }
}

int main() {
    int i,j;
    
    for(i = 1; i <= 7; i++){
        for(j = 1; j <= 7; j++){
            scanf("%d",&map[i][j]);
        }
    }
    ch[1][1] = 1;
    DFS(1,1);
    
    printf("%d",cnt);
    
    return 0;
}
/*
0 0 0 0 0 0 0
0 1 1 1 1 1 0
0 0 0 1 0 0 0
1 1 0 1 0 1 1
1 1 0 0 0 0 1
1 1 0 1 1 0 0
1 0 0 0 0 0 0
 */
