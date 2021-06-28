#include <stdio.h>
#include <vector>
using namespace std;
int main() {
    int N,K,i,pos=0, cnt = 0, bp = 0;
    
    scanf("%d %d",&N,&K);
    
    vector<int> prince(N+1);
    
    //꼭 for문으로 돌려서 i를 증가시키고
    //다 돌면 i를 1로 바꿔줄 필요 없음
    while(1){
        pos++;
        
        if (pos > N) pos = 1;
        
        if(prince[pos] == 0){
            cnt++;
            if(cnt == K){
                prince[pos] = 1;
                cnt = 0;
                bp++;
            }
        }
        
        if (bp == N-1) break;
    }
    
    for(i = 1; i <= N; i++){
        if(prince[i] == 0)
            printf("%d",i);
    }
    
    return 0;
}
