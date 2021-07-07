//BFS는 최단거리(몇몇 노드를 아예 들리질 않음)
//MST는 Cycle형태의 그래프 구조에서
//"모든 도시"를 다 들리지만 최소의 비용으로 들릴 수 있게
//새로운 트리를 뽑아냄(Cycle이 사라짐)
//Cycle을 없애려면
//이미 두 노드는 하나의 집합에 있다라고 해놓으면 됌(Union&Find)

//kruskal 알고리즘은
//간선의 비용을 정렬해서 작은 것부터 선택해 나가 되,
//cycle이 발생하지 않도록 선택하는 것.
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
int unf[10001];

struct Edge{
    int v1;
    int v2;
    int val;
    Edge(int a, int b, int c){
        v1 = a;
        v2 = b;
        val = c;
    }
    
    bool operator<(Edge &ref){ //kruskal MST는 간선을 정렬함
        return val < ref.val;
    }
}

int Find(int v){
    if(v==unf[v]) return v;
    else return unf[v] = Find(unf[v]);
}

void Union(int a, int b){
    a = Find(a);
    b = Find(b);
    if(a!=b) unf[a] = b;
}

int main() {
    vector<Edge> Ed;
    int i,n,m,a,b,c,cnt=0,res=0;
    scanf("%d %d",&n,&m);
    for(int i = 1; i <= n; i++){ //각 노드들에게 집합 번호를 부여한다.
        unf[i] = i;
    }
    
    for(int i = 1; i <= m; i++){//트리구조 만들어냄, 집합 묶음
        scanf("%d %d %d",&a, &b, &c);
        Ed.push_back(Edge(a,b,c));
    }
    sort(Ed.begin(), Ed.end());
    
    for (i = 0; i < m; i++) {
        int fa = Find(Ed[i].v1);//해당 노드의 집합 번호
        int fb = Find(Ed[i].v2);
        if(fa != fb){ // 같지 않으면 Cycle이 돌지 않으므로
            res += Ed[i].val; // 최소비용에 누적
            Union(Ed[i].v1,Ed[i].v2); //집합 연결시켜주기
        }
    }
    cin >> a >> b;
    a= Find(a);//같은 집합에 속한 학생들은 같은 집합번호(루트학생 번호)를 리턴한다.
    b= Find(b);
    if(a==b) cout<<"YES";
    else cout<<"NO";
    return 0;
}
