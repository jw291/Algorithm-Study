//스스로 해결!
//처음에 DFS그린대로 안한거(5로 시작했는데 res에 0을 넣음)
//값 넣을때 <=N으로 안한거 <N으로함)
#include <iostream>
#include <queue>

using namespace std;

int N, maximum = -2147000000,minimum = 2147000000;
int oper[5], a[10];

void DFS(int L, int res){
    int i;
    
    if(L == N){
        if(res > maximum) maximum = res;
        if(res < minimum) minimum = res;
    }
    else{
        for(i = 1; i <= 4; i++){
            if(oper[i] == 0) continue;
            if(oper[i] >= 1){
                if(i == 1) {
                    oper[i]--;
                    DFS(L+1,res + a[L+1]);
                    oper[i]++;//매개변수만 되돌아 가는게 아님 이렇게해서 되돌아갈 수 있음
                }
                else if(i == 2) {
                    oper[i]--;
                    DFS(L+1,res - a[L+1]);
                    oper[i]++;
                }
                else if(i == 3) {
                    oper[i]--;
                    DFS(L+1,res * a[L+1]);
                    oper[i]++;
                }
                else if(i == 4) {
                    oper[i]--;
                    DFS(L+1,res / a[L+1]);
                    oper[i]++;
                }
            }
        }
    }
}

int main() {
    
    queue<int> q;
    
    scanf("%d",&N);
    
    for(int i = 1; i <= N; i++){
        scanf("%d" ,&a[i]);
    }
    
    for (int i = 1; i <= 4; i++) {
        scanf("%d",&oper[i]);
    }
    
    DFS(1,a[1]); //그린대로 시작하자. Level:1에서 res:5로 시작하도록 그렸음.
    
    printf("%d\n",maximum);
    printf("%d\n",minimum);
    return 0;
}
