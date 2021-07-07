/*
 크루스칼과 프림은 가중치 그래프에서 최소비용의 트리를 뽑아내는 알고리즘입니다. 차이점은 크루스칼은 간선을 정렬하여 트리를 만들어 나가는 것이고, 프림은 정연결해 가면서 트리를 만들어 간다는 것입니다.  주로 프림보다는 크르스칼이 문제 풀때는 편합니다.  삼성 엑스퍼트 아카데미 사이트에서  "하나로"라는 문제가 대표적입니다. 백준사이트에서는 ""행성연결", "도시분할계획", "전기가 부족해" 등이 있습니다. 문제들을 읽어 보면 느낌이 올거라 생각합니다.

 다익스트라는  한 정점에서 출발하여 다른 각 정점으로 가는 데 드는 최소비용을 구하는 알고리즘입니다. 백준에서 대표적인 문제는 "파티", "도로포장",  "등산" 등이 있습니다.
 */
//prim은 간선을 선택하는게 아니라 임의의 시작 정점을 선택
//시작 정점으로부터 그래프의 연결 관계를 보면서
//트리를 만들어나가는 것
//n개를 완성하면 트리가 끝나는 것

//우선순위 큐에 비용과 간선번호를 넣어서 min heap을 이용해서 비용을 오름차순으로 정렬함
//그래프에서 갈 수 있는 모든 경로를 다 넣어야함.
//pop시키면 비용이 작은 순서대로 pop될 것이고 그 노드부터 다시 그래프를 탐색해나감
//이미 선택된 노드는 다시 선택하지 않음(회로 방지) 그냥 pop시킴
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int ch[30];

struct Edge{
    int e;
    int val;
    Edge(int a, int b){
        e = a;
        val = b;
    }
    bool operator<(const Edge &ref)const{
        //priority_queue에서 동작
        //최소힙을 만들어줌.
        return val > ref.val;
    }
};

int main() {
    priority_queue<Edge> Q;
    vector<pair<int, int>> map[30]; //인접리스트
    int i,n,m,a,b,c,res=0;
    scanf("%d %d",&n,&m);
    
    for(i = 1; i <= m; i++){
        scanf("%d %d %d",&a,&b,&c);
        map[a].push_back(make_pair(b, c));
        map[b].push_back(make_pair(a, c));//양방향 가중치 그래프 인접리스트
    }//문제에서 주어준 그래프 그리기
    
    Q.push(Edge(1,0));//노드 1에서 시작한다.
    
    while (!Q.empty()) {
        Edge tmp = Q.top(); //top 데이터 가져오고
        Q.pop();//바로 pop
        int v= tmp.e;//top데이터 노드번호 참조
        int cost = tmp.val;//top데이터 비용 참조
        if(ch[v] == 0){ //방문하지 않았다면
            res += cost;//코스트 누적
            ch[v] = 1;//방문했다.
            for(i = 0; i < map[v].size(); i++){//인접리스트와 연결된 노드 모두 참조
                Q.push(Edge(map[v][i].first, map[v][i].second));//Q에 담는다.
            }
        }
    }
    
    printf("%d\n",res);
    
    return 0;
}
/*
9 12
1 2 12
1 9 25
2 3 10
2 8 17
2 9 8
3 4 18
3 7 55
4 5 44
5 6 60
5 7 38
7 8 35
8 9 15
 */
