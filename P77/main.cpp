//disjoint-set 서로소 집합 : 공통원소가 없는 집합
//disjoint-set은 트리로 구현함
//두 집합간의 관계를 공통원소를 통해 알 수 있다면
//공통원소가 있으면 한 집합으로 묶어버리면됌
//한 집합은 트리로 구성되어 있음
//두 노드가 서로 다른 집합(트리)에 있다면 disjoint-set이므로 친구가 아니다.
#include <iostream>
using namespace std;

int unf[1001];//1차원 배열의 트리형태

int Find(int v){
    //v라는 학생의 집합번호를 리턴하는 역할
    //결국 연결된 집합의 학생들은 루트번호학생의 번호가 집합번호가 되어 리턴함.
    if(v==unf[v]) return v;
    else return unf[v] = Find(unf[v]);//메모이제이션(경로 압축)
}

void Union(int a, int b){
    a = Find(a);
    b = Find(b);
    if(a!=b) unf[a] = b;//서로 다른 집합에 있다. unf[1] = 2 : 1-2 연결
}

int main() {
    int n,m,a,b;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){ //각 학생들에게 집합 번호를 부여한다.
        unf[i] = i;
    }
    
    for(int i = 1; i <= m; i++){//트리구조 만들어냄, 집합 묶음
        cin >> a >> b;
        Union(a,b);
    }
    
    cin >> a >> b;
    a= Find(a);//같은 집합에 속한 학생들은 같은 집합번호(루트학생 번호)를 리턴한다.
    b= Find(b);
    if(a==b) cout<<"YES";
    else cout<<"NO";
    return 0;
}
/*
9 7
1 2
2 3
3 4
4 5
6 7
7 8
8 9
3 8
 */
