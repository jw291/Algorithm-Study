//처음엔 BFS를 생각했음 가장 최상의 방법을 찾는 문제이기 때문에
//하지만 BFS려면 순서와 상관없이 트리를 만들어서 가장 큰 비용을 가지는 루트를 구하느 건데
//1~7일이라는 순서가 정해져있음
//그래서 일단 1일을 결정했을 때 뻗어나가는 가지
//2일을 결정했을 때 뻗어나가는 가지 이렇게 가지를 하나하나 그려봐야함
//이건 7일이라는 만약 BFS로 7일까지 너비탐색을 해봐야 의미가 없음
//1일부터 깊게 들어가면서 연결점을 따져봐야함(모든 경우의 수를 살펴봐야함)

//조심해야될 것. 만약 7일차의 상담일이 2일이라고 쳐보면
//7일에 상담을 받으면 7,8일 상담을 받고 9로 넘어간다.
//n은 7일이기 때문에 8일차에 상담을 받아선 안된다.
//따라서 무조건 레벨이 8에서 멈춰야한다.

//상담을 한다,안한다 두가지로 나눠서함.
//엄청 햇깔림..
//처음에는 모든 가지가 7개로 뻗어나가게끔 생각했음
//그럴 필요가 없는게 어차피 방향이 정해져있음, 이전 일수는 고려할 필요 없음
//따라서 한다 안한다 두 가지로 나눠서 생각하는게 더 좋음.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<pair<int, int>> a;
int res = -2147000000;
void DFS(int v, int sum){
    if(v == N+1){
        if(sum > res) res = sum;
    }
    else{
        if(v+a[v].first<= N+1)//한다면 날짜를 더해줌 더해주는데 8일을 넘어가지 않아야함.
            DFS(v+a[v].first, sum+a[v].second);
        
        DFS(v+1,sum);//안한다면 바로 다음칸
    }
}

int main() {
    int T,P;
    scanf("%d",&N);
    
    a.push_back(make_pair(0, 0));
    for(int i = 1; i <= N; i++){
        scanf("%d %d", &T, &P);
        a.push_back(make_pair(T, P));
    }
    
    DFS(1,0);
    
    printf("%d",res);
    return 0;
}
/*
7
4 20
2 10
3 15
3 20
2 30
2 20
1 10
 */
