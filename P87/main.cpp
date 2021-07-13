//아이디어는 맞췄는데
//무조건 최상단 loop가 while(!q.empty())이어야 빠르다는 생각때문에
//생각의 폭이 좁아짐.

#include <iostream>
#include <algorithm>
#include <queue>

int dx[8] = {-1,-1, 0, 1, 1, 1, 0,-1};//행
int dy[8] = { 0, 1, 1, 1, 0,-1,-1,-1};//열
using namespace std;

int ch[22][22];
int map[22][22];

int main() {
    int N,tmp;
    scanf("%d",&N);
    pair<int,int> _x;
    
    queue<pair<int, int>> island;
    queue<pair<int, int>> q;
    int cnt = 0;
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            scanf("%d",&tmp);
            map[i][j] = tmp;
        }
    }
    puts("");
    
    //원래는 queue로 섬만 탐색하도록 했었는데
    //queue로 하니까 자기자신에 대한 카운터를 못했음
    //그래서 map[6][2]도 하나의 섬인데 ++을 안함
    //그래서 i,j로 탐색해서 자기 자신도 탐색하도록 함
    //코드도 간결하고 결과적으로 속도도 비슷할듯
    //거의 혼자 해결했음
    //bfs라고 무조건 !q.empty로 묶을 필요는 없음.
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(map[i][j] == 1 && ch[i][j] == 0)
            {
                ch[i][j] = 1;
                q.push(make_pair(i,j));
                
                while(!q.empty()){
                    pair<int,int> __x = q.front();
                    q.pop();

                    for(int i = 0; i < 8; i++){
                        int __row = __x.first + dx[i];
                        int __col = __x.second + dy[i];
                        if(map[__row][__col] == 1 && ch[__row][__col] == 0)
                        {
                            ch[__row][__col] = 1;
                            q.push(make_pair(__row, __col));
                        }
                    }
                }
                cnt++;
            }
        }
    }
        
    
    printf("%d\n",cnt);
    return 0;
}
/*
7
1 1 0 0 0 1 0
0 1 1 0 1 1 0
0 1 0 0 0 0 0
0 0 0 1 0 1 1
1 1 0 1 1 0 0
1 0 0 0 1 0 0
1 0 1 0 1 0 0
 
 */
