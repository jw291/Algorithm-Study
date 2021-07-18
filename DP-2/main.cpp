//top down방식 (재귀,메모이제이션)
//DFS(7)을 호출하면 7미터짜리 선을 1,2m로 자르는 경우의 수를 리턴받는다.
//7이면 6미터를 자르는 경우의 수 + 1미터를 자르는 경우의 수(1)
//5미터를 자르는 경우의 수 + 2미터를 자르는 경우의 수(2)
//이 두 가지의 경우의 수를 더하면 되는 것.
//DFS가 쭉 밑으로 가다보면 D(2) D(1)만 남는데 이 두 가지는 직관적으로 알 수 있는 수이다.
#include <iostream>

int dy[101];//다이나믹 배열 메모이제이션

#include <iostream>

using namespace std;

int DFS(int n){
    if(dy[n] != 0) return dy[n]; //가지치기
    if(n == 1 || n == 2) return n; //dfs(1)은 한가지 dfs(2)는 두가지
    else return dy[n] = DFS(n-1) + DFS(n-2);
}

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    cout << DFS(n);
    return 0;
}
