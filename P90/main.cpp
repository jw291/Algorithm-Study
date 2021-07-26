//아이디어는 전체적으로 맞았는데
//dis에 대한 처리가 어려움
//무조건 심바 위치로부터의 거리를 생각했는데
//거리를 누적해서 해야된다는 생각을 못했음

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int dx[4] = {1,0,0,-1};
int dy[4] = {0,1,-1,0};
int map[26][26];
int ch[26][26];

struct Loc{
    int x;
    int y;
    int dis;
    
    Loc(int ra_x, int ra_y, int ra_dis){
        x = ra_x;
        y = ra_y;
        dis = ra_dis;
    }
    
     bool operator<(const Loc &ref)const{
         if(dis != ref.dis)
           return dis > ref.dis;
         else{
             if(x != ref.x) return x > ref.x;
             else if(x == ref.x) return y > ref.y;
         }
         return 0;
     }
};

struct Simba{
    int x;
    int y;
    int ate;
    int size;
    
    void Sizeup(){
        size++;
        ate = 0;
    }
};
int main() {
    ios_base::sync_with_stdio(false);
    int N;
    cin >> N;
    Simba simba;
    priority_queue<Loc> pQ;
    int res = 0;
    
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            cin >> map[i][j];
            
            if(map[i][j] == 9){
                simba.x = i;
                simba.y = j;
                map[i][j] = 0;
            }
        }
    }
    simba.size = 2;
    simba.ate = 0;
    
    pQ.push(Loc(simba.x,simba.y,0));
    
    while (!pQ.empty()) {
        Loc tmp = pQ.top();
        pQ.pop();
        int x = tmp.x;
        int y = tmp.y;
        int dis = tmp.dis;
        
        if(map[x][y] < simba.size){ //어차피 처음엔 통과됌
            if(map[x][y] != 0){ //잡아먹음
                simba.x = x;
                simba.y = y;
                simba.ate++;
                if(simba.ate >= simba.size) simba.Sizeup();
                
                map[x][y] = 0; //잡아먹었으니까 0
                
                for(int i = 1; i <= N; i++){ //다시 전부 0으로 초기화해주고 거리 싹다 계산할거
                    for(int j = 1; j <= N; j++){
                        ch[i][j] = 0;
                    }
                }
                
                while (!pQ.empty()) pQ.pop(); //잡아먹었으니까 pQ도 다시 없애버림
                
                res = tmp.dis; // 심바의 처음위치부터 계속 움직이면서 누적된 거리값
            }
        }
        
        for(int i = 0; i < 4; i++){//다시 싹다 돌면서 거리계산해주면서 pQ에 넣어버림
            int _x = x+dx[i];
            int _y = y+dy[i];
            if(_x < 1 || _x > N || _y < 1 || _y > N || map[_x][_y] > simba.size || ch[_x][_y] > 0) continue;
            
            pQ.push(Loc(_x,_y,dis+1));
            ch[_x][_y] = 1;
        }
    }
    
    cout << res;
    return 0;
}
/*
3
0 1 3
1 9 1
0 1 1
 */
