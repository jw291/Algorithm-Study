//스스로 해결!
#include <iostream>
#include <vector>

using namespace std;

int g[21][21],ch[21][21];
int cost = 2147000000;
vector<int> res;
int N;

void DFS(int v,int sum){
    int i;
    
    if(v == N){
        if(sum < cost){
            cost = sum;
        }
    }
        //res.push_back(sum); 이렇게할 필요도 없음
    else{
        for(i = 1; i <= N; i++){
            if(g[v][i] > 0 && ch[v][i] == 0){
                ch[v][i] = 1;
                DFS(i,sum+g[v][i]);
                ch[v][i] = 0;
            }
        }
    }
}

int main() {
    int M,i,j,v,v2,w;
    scanf("%d %d",&N,&M);
    
    for(i = 1; i <= M; i++){
        scanf("%d %d %d",&v,&v2,&w);
        g[v][v2] = w;
    }
    ch[1][1] = 1;
    DFS(1,0);
    
    /*
    for(i = 0; i < res.size(); i++){
        if(res[i] < min){
            min = res[i];
        }
    }*/
    
    printf("%d",cost);
    
    return 0;
}
/*
5 8
1 3 12
1 3 6
1 4 10
2 3 2
2 5 2
3 4 3
4 2 2
4 5 5
 */
