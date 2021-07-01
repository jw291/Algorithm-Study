//부분 집합, 수 많은 경우의 수 중 최적의 답 = DFS

#include <iostream>
#include <vector>

using namespace std;

vector<int> a;
int tot = 0;
//dfs sum누적 알아놓기

void DFS(int i){
    
    if(i > a.size()) return;
    else{
        sum += a[i];
        DFS(i*2);//왼
        DFS(i*2+1);//오
    }
}

int main() {
    int N,tmp;
    int sum;
    scanf("%d",&N);
    
    for(i = 1; i <= N; i++){
        scanf("%d",&tmp);
        a.push_back(tmp);
        tot += a[i];
    }
    tot = sum/2;
    
    DFS(1);
    
    return 0;
}
