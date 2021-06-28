//이것도 이전 문제와 같이
//반복을 다시 처음부터 시작해야하는 경우
//스스로해결
//이런 문제는 if문 여러개 써야하는데 순서가 꽤 까다로움
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int N,K,i,tmp,res,cnt=0,idx=0,tot=0;
    
    scanf("%d",&N);
    
    vector<int> work(N);
    
    for(i = 1; i <= N; i++){
        scanf("%d",&work[i]);
        tot += work[i];
    }
    
    scanf("%d",&K);
    
    if(K >= tot){
        res = -1;
        printf("%d",res);
        return 0;
    }
    
    while(1){
        idx++;
        
        if(work[idx] >= 1){
            work[idx]--;
            cnt++;
            if(cnt > K) {
                res = idx;
                printf("%d",res);
                break;
            }
        }
        
        if(idx == N) idx = 0;
        
    }
    
    
    
    
    return 0;
}
