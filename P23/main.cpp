#include <iostream>
//스스로 해결!
//채점 필요
int main() {
    int n, i, pre, now, cnt = 0, max = -2147000000;
    
    scanf("%d", &n);
    scanf("%d", &pre);
    cnt = 1;
    max = 1;
    
    for(i = 2; i <= n; i++){
        scanf("%d", &now);
        if(now >= pre){
            cnt++;
            if(cnt > max) max = cnt;
        }
        else cnt = 1;
        pre = now;
    }
    
    printf("%d\n",max);
    /*
    int N, num, res = 0, cnt=0, max = -2147000000;
    
    scanf("%d",&N);
    
    for(int i = 1; i <= N; i++){
        scanf("%d",&num);
        if(num >= max){
            max = num;
            cnt++;
        }else {
            max = num;
            cnt = 1;
        }
        printf("cnt : %d \n",cnt);
        if(cnt > res) res = cnt;
    }
    
    printf("%d",res);
    return 0;*/
    
}
