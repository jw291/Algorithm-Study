//위상정렬 알고리즘
//그래프 (인접리스트로 구현 해야함)
//4번 노드의 차수(연결된 간선의개수)는 3개다
//하지만 진입차수는 2개

//따라서 진입차수에 대한 배열degree에 기록한다
//1 4는 4에 1추가
//5 4는 4에 1추가
//4 3은 3에 1추가 ... 이런식으로
//그럼 4는 먼저 처리해야할 작업이 두개있다
//3은 먼저 처리해야할 작업이 두개 있다. 이런식으로 해석할 수 있다.


//그리고 queue를 이용한다.
//degree행렬에 for문을 돌면서 0인(선행 작업이 없는) 노드를 queue에 넣는다.
//그 다음 queue에서 하나 뺀다(bfs처럼) (의미 : 일을 했다)
//1번 작업을 queue에서 뺏다면 작업을 한 것이므로 degree 4번을 하나 뺀다
//그 다음 6번을 queue에서 빼면 degree 2번을 하나 뺀다.
//이제 degree 2가 0이 됐으므로
//degree 3감소 degree 5감소시킨다.
//이제 degree 5가 0이므로 queue에 넣고 꺼낸다.
//이제 4를 꺼내고 degree 3을 하나 감소시킨다.
//그러면 1 6 2 5 4 3이라는 순서가 나오고 queue는 비어서 끝난다.
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int n,m,a,b,score;
    cin >> n >> m;
    vector<vector<int>> graph(n+1, vector<int>(n+1,0));
    vector<int> degree(n+1);
    queue<int> Q;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        graph[a][b] = 1; //그래프화 시킴
        degree[b]++;//degree배열에 진입배열 몇개있는지 카운팅함
    }
    for(int i = 1; i <= n; i++){
        if(degree[i] == 0) Q.push(i);
        //진입차수가 없다면(선행작업이 없다면 push)
        //선행작업이 없어야 일을 할 수 있으므로(다른건 1번일을 하고 난 후 4번일을 해야함)
    }
    
    while (!Q.empty()) {
        int now = Q.front();//Q엔 진입차수가 없는 값들이 담겨있음 여기서 하나 뺌
        Q.pop();
        cout << now << " ";//출력함
        for(int i = 1; i <= n; i++){
            //now가 만드는 진입차수를 하나 뺌 1->4라면 degree 4하나 감소 1을 했으므로
            if(graph[now][i] == 1){
                degree[i]--;
                if(degree[i] == 0) Q.push(i); //그와 동시에 선행작업 없는 애를 Q에 넣음4
            }
        }
    }
    return 0;
}
