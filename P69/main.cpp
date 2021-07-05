//레벨순으로 탐색, 너비우선 탐색
//큐를 이용해서 구현한다.
//1번 레벨에서 가장 가까운 노드들을 다 방문하고(레벨로)
//그 다음 가장 가까운 노드 다 방문하고
//이런 구조를 통해 최단거리를 알 수 있는 것이다.
#include <iostream>
#include <vector>

using namespace std;

int Q[100], front = -1, back = -1, ch[10];
vector<int> map[10];

int main() {
    int i, a, b, x;
    for(i = 1; i <=6; i++){
        scanf("%d %d", &a, &b);
        map[a].push_back(b);
        map[b].push_back(a); //무방향 인접리스트
    }
    Q[++back] = 1;//1번 루트노드
    ch[1] = 1;//방문했다
    
    while (front < back) {
        //front로 빼내고 back으로 값 넣는다.
        //같아지는 순간 끝나는거
        x = Q[++front];
        printf("%d ", x);
        for(i = 0; i < map[x].size(); i++){
            if(ch[map[x][i]] == 0){
                ch[map[x][i]] = 1;
                Q[++back] = map[x][i];
            }
        }
    }
    return 0;
}
/*
1 2
1 3
2 4
2 5
3 6
3 7
 */
