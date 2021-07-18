#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int dx[4]={1,0,0,-1};
int dy[4]={0,1,-1,0};
int box[1000][1000];
int dis[1000][1000];
int main() {
    int N,M,tmp;
    pair<int,int> x;
    queue<pair<int,int>> q;
    int num = 0, cnt = 0;
    int res = 0;
    scanf("%d %d",&N,&M);
    
    for(int i = 0; i < M; i++){
        for(int j = 0 ; j < N; j++){
            scanf("%d",&tmp);
            box[i][j] = tmp;
            if(tmp == 1){
                q.push(make_pair(i, j));
                num++;
            }
        }
    }
    
    while(!q.empty()){
        x = q.front();
        q.pop();
        
        for (int i = 0; i < 4; i++) {
            int _row = x.first + dx[i];
            int _col = x.second + dy[i];
            
            if((_row > M-1 || _row < 0)||(_col > N-1 || _col < 0)) continue;
            
            if(box[_row][_col] == 0){
                q.push(make_pair(_row, _col));
                box[_row][_col] = 1;
                dis[_row][_col] = dis[x.first][x.second]+1;
                cnt++;
                res = dis[_row][_col];
            }
        }
    }

    if(cnt == 0) printf("0");
    else if(cnt != (N*M - num)) printf("-1");
    else if(cnt == (N*M - num)) printf("%d",res);
    return 0;
}
/*
6 4
0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 0 1
 */
