#include <iostream>
#include <vector>

//#define x first
//#define y second
//난 그냥 first second가 더 좋음

using namespace std;

vector< pair<int,int> > g[21];
int ch[6];
int N, cost = 2147000000;

void DFS(int v, int sum){
    int i;
    
    if(v == N) {
        if(sum < cost) cost = sum;
    }
    else{
        for(i = 0; i < g[v].size(); i++){
            if(ch[g[v][i].first] == 0){
                ch[g[v][i].first] = 1;
                DFS(g[v][i].first,sum+g[v][i].second);
                ch[g[v][i].first] = 0;
            }
        }
    }
}

int main() {
    int M;
    int i;
    int v,v2,w;
    scanf("%d %d",&N,&M);
    
    for(i = 0; i < M; i++){
        scanf("%d %d %d",&v,&v2,&w);
        g[v].push_back(make_pair(v2, w));
    }
    ch[1] = 1;
    DFS(1,0);
    
    printf("%d",cost);
    
    return 0;
}
