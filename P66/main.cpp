//64번 문제 인접리스트 버전
//인접행렬일 때 n = 1000이면 map[1000][1000]으로 잡고
//1과 연결된 노드를 찾기 위해 [1][1~1000]까지 돌아야함
//인접리스트일 때 n = 1000이면 map[1000]으로 잡고
//push back으로 바로 연결시켜줌
//1번과 연결된 값을 찾는다치면 이미 인접리스트로 연결되어있어서 훨씬 편함
//그냥 [1]에 이미 들어있는 값들이 1과 연결된 값이니까 0부터 map[1].size()만큼 돌면댐
#include <iostream>
#include <vector>
using namespace std;
int ch[30], cnt = 0, n;
vector<int> map[30];//map이라는 벡터 30개 생성

void DFS(int v){
    int i;
    if(v==n) cnt++;
    else{
        for(i = 0; i < map[v].size(); i++){
            //인접리스트로 학인해서 if로 확인할 필요도 없음 이젠
            //체크배열만 확인하면 댐
            if(ch[map[v][i]] == 0)//map[v][i]는 v하고 연결된 노드의 번호
            {
                ch[map[v][i]] = 1;
                DFS(map[v][i]);//v와 연결된 노드로 이동
                ch[map[v][i]] = 0;
            }
        }
    }
}

int main() {
    int m,i,a,b;
    
    scanf("%d %d",&n,&m);
    
    for(i = 1; i <= m; i++){
        scanf("%d %d",&a, &b);
        map[a].push_back(b);//편리하네
    }
    
    ch[1] = 1;
    DFS(1);
    printf("%d",cnt);
    return 0;
}
