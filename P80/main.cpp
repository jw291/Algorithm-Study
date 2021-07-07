//다익스트라 : 최단거리(간선값이 양수일때만 사용)
//BFS로도 풀 수 있는데, 다익스트라는 DP에 가까운 알고리즘임 노드가 많아질수록 더 효과적임
//BFS는 같은 정점이 여려번 입력될 수도 있기 때문임
//하지만 다익스트라는 무조건 엣지가 양수여야한다는 걸 잊어선 안됌.
//글고 벨만포드에 비해서 시간복잡도가 더 빠름(greedy라고함 알아보자)
//벨만포드는 음수도 처리가능함. 그래서 웬만하면 다익스트라쓰되, 음수도 처리해야하면 벨만포드 쓰기

//인접리스트로 그래프 그려놓고
//시작정점에서부터 다른 노드까지의 거리를 무한대로 초기화해놓음
//min사용하듯이

//1에서 처음으로 뻗어나간거 보니까 2,12 3,4임
//dist배열에 2 : 12저장하고 3 : 4저장해놓음 나머진 다 2147000000
//쭉 훑었을때 가장 작은 값은 3 : 4임
//3번 노드까지 가는 거리는 절대적으로 4보다 작을 수 없음
//이미 1->2->3으로 갈 수있다 쳐도 1->2가 이미 12임.(다익스트라는 양수만 가능함 음수가 없어서 절때 불가능)
//즉, 시작 노드와 곧바로 연결된 노드중 가장 작은 노드는 그 거리가 무조건 가장 최단거리가 됌.
//그래서 3번 정점에서부터 이제 쭉 퍼져나가도 상관없음
//3->4만 가능함. 그럼 무조건 4번 노드는 1->3->4(9)가 최단거리임
//또 훑었을때 4 : 9가 가장 작으니까 4에서 시작함
//4->2 4->5가능함.
//4->2보니까 11임 1->2 12보다 작음 11로 교체함
//참고로, 체크한애는 다시 최소 찾으면 안됌

//정리하자면,
//시작 노드로부터 연결된 노드 중에서 비용이 가장 작은 노드는 더이상 최단 거리가 존재하지 않음(다익스트라는 양수만 가능해서)
//그래서 시작노드로부터 연결된 노드중에서 비용이 가장 작은 노드로부터 연결된 노드를 쭉 살펴보기 시작함
//그다음 dist에 누적 값을 넣음
//이제 dist에서 체크안된 노드들을 쑥 훑어보면서 가장 비용이 작은 노드로부터 또 다시 시작함(다익스트라는 양수만 가능해서 무조건 최단거리임)
//근데, 쑥 훑을때 노드의 수가 많아지면 비효율적으로 되니까 우선순위 큐에 min heap에 넣어서 관리함
//그럼 n->logn번만에 찾음

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

struct Edge{
    int vex;
    int dis;
    Edge(int a, int b){
        vex = a;
        dis = b;
    }
    bool operator<(const Edge &ref)const{
        return dis > ref.dis;
    }
};

int main() {
    priority_queue<Edge> pQ;
    vector<pair<int,int>> graph[30];//인접리스트 그래프 그리기
    int i, n, m, a, b, c;
    cint >>n>>m;
    vector<int> dist(n+1, 2147000000);//벡터 초기화
    for(i = 1; i <= m; i++){
        cin >> a >> b >> c;
        graph[a].push_back(make_pair(b, c));
    }
    Q.push(Edge(1,0));
    dist[1] = 0; //거리 넣음
    
    while(!Q.empty()){
        int now=Q.top().vex;
        int cost=Q.top().dis; //훑었을때 dis가 가장 작은 값에서부터 시작
        
        Q.pop();//보통 값 넣고 바로 pop하네
        
        if(cost > dist[now]) continue;
        //dis[now]에는 원래 있던 값, cost에는 새로 들어온 값
        //원래 있던 값이 더 작으면 걍 넘어가
        
        for(i = 0; i<graph[now].size(); i++){
            int next = graph[now][i].first; //연결된 노드번호
            int nextDis = cost+graph[now][i].second//연결된 노드와의 cost누적
            if(nextDis < dist[next]){ //원래 들어있던 값보다 누적값이 더 작으면
                dist[next] = nextDis; //바꿔주기
                Q.push(Edge(next,nextDis)); //새롭게 푸쉬하기
            }
        }
    }
    for(i = 2; i <= n; i++){
        if(dist[i] != 2147000000) cout << i< << " : " << dist[i] << endl;
        else cout << i << " : impossible" << endl;
    }
    
    return 0;
}
