#include <iostream>
#include <algorithm>

int a[20],res[20],ch[20];
int n,r,cnt = 0;

void DFS(int L){
    //레벨로 나눔
    //각 레벨에서 모든 1,3,6,7 경우의 수 즉, 네가지의 가지로 뻗어나감 여기까진 해결함
    //그런데 정렬이 안된 상태로 출력됨
    //생각해보면 0에서 시작해서 네개의 가지로 뻗어나가고 각 가지들이 시작점이 됌.
    //DFS(1)은 1,3,6,7이렇게 있음 즉, 해당 레벨에 값을 넣어주어야함
    //res[L] = a[i]이렇게.그럼 res[1]에 3이 들어가서 3 1 6 / 3 1 7 / 3 6 1 이런식으로 가능하게됌.
    //레벨을 잘 활용해야함.
    //이 문제와 복면산 푸는 방식 똑같음
    
    if(L == r){
        for(int j = 0; j<L; j++){
                printf("%d ",res[j]);
        }
        cnt++;
        puts("");
    }
    else{
        for(int i = 1; i<=n; i++){
            if(ch[i] == 1) continue;
            else{
                res[L] = a[i]; //각 레벨에 대한 값을 그때그때 할당해준다. 그래야 정렬된 값이 나온다.
                ch[i] = 1;
                DFS(L+1);
                ch[i] = 0;
            }
        }
    }
}

int main() {
    int i;
    scanf("%d %d",&n,&r);
    
    for(i = 1; i <= n; i++){
        scanf("%d",&a[i]);
    }
    DFS(0);
    
    printf("%d",cnt);
    
    
    return 0;
}
