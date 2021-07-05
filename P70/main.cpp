//bfs 그래프 최단거리
//1에서 갈 수 있는 가장 가까운 레벨(가장 가까운 노드 3,4)에 있는 모든 노드를 체크해버림
//그래서 그 다음 3에서 가장 가까운 노드가 4더라도 못감
//이런 구조로 하다보니 최소 이동 거리가 만들어짐


#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){
    int N,M;
    int i;
    int v,v2;
    int x;
    
    vector<int> g[21];
    queue<int> q;
    int dis[30] = {0};
    int ch[30] = {0};
    
    scanf("%d %d",&N,&M);
    
    for(i = 1; i <= M; i++){
        scanf("%d %d",&v,&v2);
        g[v].push_back(v2);//인접리스트, 방향그래프 v에서 갈 수 있는 노드는 v2
    }
    
    q.push(1);
    ch[1] = 1;
    while (!q.empty()) {
        x = q.front();
        //어차피 pop하기 때문에 back이나 front나 같은데
        //front가 더 정확함
        q.pop();
        for(i = 0; i < g[x].size(); i++){
            if(ch[g[x][i]] == 0){
                ch[g[x][i]] = 1;
                q.push(g[x][i]);
                dis[g[x][i]] = dis[x] + 1;
            }
        }
        //ch[g[q.back()][i]] = 0;
    }
    
    for(i = 2; i <= N; i++){
        printf("%d : %d\n",i,dis[i]);
    }
}
/*
vector<int> g[21];
int dis[7]; //출벌인덱스부터 인덱스번호 = 노드번호까지 도달할 수 있는 최소 간선의 개수(최단거리)가 저장됨

queue<int> q;


void BFS(int vertex,int distance){
    int i;
    
    if(q.empty()) return;
    else
    {
        for(i = 0; i < g[vertex].size(); i++) {
            if(dis[g[vertex][i]] == 0){
                q.push(g[vertex][i]);
                dis[g[vertex][i]] = distance + 1;
            }
        }
        q.pop();
        BFS(q.back(),dis[q.back()]);
    }
}

int main() {
    int N, M;
    int v, v2;
    int i;
    scanf("%d %d",&N, &M);
    for(i = 0; i < M; i++){
        scanf("%d %d",&v,&v2);
        g[v].push_back(v2);//인접리스트, 방향그래프 v에서 갈 수 있는 노드는 v2
    }
    q.push(1);
    BFS(1,0);
    
    for(i = 2; i <= N; i++){
        printf("%d : %d",i,dis[i]);
    }
    return 0;
}*/
/*
6 9
1 3
1 4
2 1
2 5
3 4
4 5
4 6
6 2
6 5
 */
