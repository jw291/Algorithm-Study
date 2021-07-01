//부분집합개수 2^n(공집합 포함)
//DFS레벨로 구성하기
//출력에서 전위순회라고 힌트를 줬으니까
//출력문을 보면서 규칙성을 유추해내야한다.
//
//커뮤니티 글
//DFS : 모든 경우의 수를 일일히 확인해서 최상의 경우를 찾는 경우
//그래서 부분집합 다루는 경우에 DFS를 많이 쓰는것 같음

//BFS : 최단거리를 찾거나 최소횟수를 찾는 문제
#include <iostream>

int n, ch[11];

void DFS(int L){
    int i;
    if(L==n+1){
        for(i = 1; i <= n; i++){
            if(ch[i] == 1) printf("%d ",i);
            
        }
        puts("");
    }
    else{
        ch[L] = 1;
        DFS(L+1);
        ch[L] = 0;
        DFS(L+1);
        //끝까지 하면 어차피 스택에서 사라진다는걸 알자
        //그래서 마지막 노드까지 탐색해야하는 경우
        //다 사라질대까지 하기 때문에
        //if문 리턴이 굳이 필요가 없다.
    }
}

using namespace std;
int main() {
    scanf("%d",&n);
    DFS(1);//1레벨부터
    return 0;
}
