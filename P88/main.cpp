//숫자 0이 경로인 경우의 문제
//if((1 > row || row > 7) || (1 > col || col > 7)) continue;
//미로 바깥범위를 고려하지 않도록 처리

//경로 갯수세는게 까다롭네 DFS는 쉬운데
//BFS는 모든 곳으로 뻗어나가다보니 까다로움
//아 +1씩 누적해서 더해주면 되구나
//dis배열 만들어서 누적해주기
//그리고 ch배열 만들지말고 그냥 1로 바꿔버려
//DFS에서나 ch배열 만들어야해 다시 되돌아가야하니까
//근데 bfs는 다시 되돌아갈 필요없으니까 1로 고정시켜버리기


#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
int dx[4] = {-1, 0, 1, 0};//행
int dy[4] = { 0, 1, 0,-1};//열
int map[8][8];
int dis[8][8];
int res = 0;
int main() {
    bool flag = false;
    queue<pair<int, int>> q;
    pair<int, int> x;
    for (int i = 1; i <= 7; i++) {
        for(int j = 1; j <= 7; j++){
            scanf("%d",&map[i][j]);
        }
    }
    
    q.push(make_pair(1,1));
    map[1][1] = 1;
    while(!q.empty() && !flag){
        x = q.front();
        q.pop();
        
        for(int i = 0; i < 4; i++){
            int row = x.first + dx[i];
            int col = x.second + dy[i];
            
            if((1 > row || row > 7) || (1 > col || col > 7)) continue; //제한 걸어두기
            
            if(map[row][col] == 0){
                if(row == 7 && col == 7) {
                    flag = true;
                    dis[row][col] = dis[x.first][x.second] + 1;
                    break;
                }
                else{
                    q.push(make_pair(row, col));
                    map[row][col] = 1;
                    dis[row][col] = dis[x.first][x.second] + 1;
                }
            }
        }
    }
    
    if(!flag) printf("-1");
    else printf("%d",dis[7][7]);
    
    return 0;
}
/*
0 0 0 0 0 0 0
0 1 1 1 1 1 0
0 0 0 1 0 0 0
1 1 0 1 0 1 1
1 1 0 1 0 0 0
1 0 0 0 1 0 0
1 0 1 0 0 0 0
 */
