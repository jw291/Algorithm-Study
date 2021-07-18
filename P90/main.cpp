#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int map[26][26];
int ch[26][26];
int dx[4] = {-1,0,0,1};
int dy[4] = {0,-1,1,0};

struct Loc{
    int x;
    int y;
    int dis;
    
    Loc(int a, int b, int c){
        x = a;
        y = b;
        dis = c;
    }
    
    bool operator<(const Loc &ref)const{
        if(dis == ref.dis){
            if( x == ref.x) return y > ref.y;
            else return x > ref.x;
        }else return dis > ref.dis;
        return 0;
    }
};

struct Simba{
    int x,y,size,ate;
    void sizeUp(){
        ate = 0;
        size++;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    Simba simba;
    priority_queue<Loc> pQ;
    int N;
    scanf("%d",&N);
    int res =0;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            scanf("%d",&map[i][j]);
            if(map[i][j] == 9){
                simba.x = i;
                simba.y = j;
                map[i][j] = 0;
            }
        }
    }
    
    pQ.push(Loc(simba.x,simba.y,0));
    simba.size = 2;
    simba.ate = 0;
    
    while (!pQ.empty()) {
        Loc tmp = pQ.top();
        pQ.pop();
        int x = tmp.x;
        int y = tmp.y;
        int z = tmp.dis;
        
        if(map[x][y] != 0 && map[x][y] < simba.size) {
            simba.x = x;
            simba.y = y;
            simba.ate++;
            if(simba.ate > simba.size) simba.sizeUp();
            map[x][y] = 0;
            for(int i = 0; i <= N; i++){
                for(int j = 0; j <= N; j++){
                    ch[i][j] = 0;
                }
            }
            while(!pQ.empty()) pQ.pop();
            res = tmp.dis;
        }
        
        for(int i = 0; i < 4; i++){
            int _row = x + dx[i];
            int _col = x + dy[i];
            if(_row < 1 || _row > N || _col > N || map[_row][_col] > simba.size || ch[x][y] > 0) continue;
            pQ.push(Loc(_row,_col,z+1));
            ch[_row][_col] = 1;
        }
    }

    printf("%d\n",res);
    
    return 0;
}
/*
3
0 1 3
1 9 1
0 1 1
 */
