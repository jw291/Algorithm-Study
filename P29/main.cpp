#include <iostream>
//11,12번 문제, 29, 30번문제 비슷
int main() {
    
    int N,tmp,i,cnt=0;
    
    scanf("%d",&N);
    
    for(i = 1; i <= N; i++){
        tmp = i;
        while(tmp > 0){
            if(tmp % 10 == 3) cnt++;
            tmp = tmp/10;
        }
    }
    
    printf("%d",cnt);
    return 0;
}
