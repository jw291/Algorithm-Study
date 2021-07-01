//부분 집합, 수 많은 경우의 수 중 최적의 답 = DFS

#include <iostream>
#include <vector>

using namespace std;

int a[11];
int N,tot = 0;
bool flag = false;
//dfs sum누적 넘기기, 배열도 레벨을 이용할 수 있음
//한계점을 지정해 놓는 것 중요함
//어느 시점에 리턴할지 중요함.
//한계점에서 무조건 리턴하는 것이 아님.

void DFS(int L, int sum){//L이 곧 인덱스를 가리킴
    if(sum > (tot/2)) return;// 이전 으로
    if(flag == true) return; // 스택프레임 모조리 삭제
    if(L == N+1){
        if(sum == (tot-sum))
            flag = true;
    }
    else{
        DFS(L+1, sum+a[L]);
        DFS(L+1, sum);
        //L이 7까지 내려감
        //7까지 내려가보고 sum == (total-sum)에 걸리면 정답임
        //sum이 total/2 넘어가버리면 스택 밑으로 내려감
    }
}

int main() {
    int i,tmp;
    
    scanf("%d",&N);
    
    for(i = 1; i <= N; i++){
        scanf("%d",&a[i]);
        tot += a[i];
        cout << tot;
    }
    
    DFS(1,0);
    
    if(flag) printf("YES");
    else printf("NO");
    return 0;
}
