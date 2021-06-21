#include <iostream>
#include <math.h>
#include <vector>

using namespace std;
int main() {
    int n, i, now, pre , pos;
    scanf("%d", &n);
    vector<int> ch(n);
    scanf("%d", &pre);
    
    for(i = 1; i < n; i++){
        scanf("%d", &now);
        
        pos = abs(pre-now);
        if(pos > 0 && pos <= n-1 && ch[pos] == 0){//중복되지 않아야함.
            ch[pos] = 1;
        }else{
            printf("NO\n");
            return 0;
        };
        
        pre = now;
    }
    
    printf("YES\n");
    /*
    int N,minus,cnt = 1;
    scanf("%d",&N);
    vector<int> num(N);
    
    for(int i = 0; i < N; i++){
        scanf("%d",&num[i]);
    }
    
    minus = num[0] - num[1];
    if(1 > abs(minus) && abs(minus) >= N-1){
        printf("NO");
        printf("minus : %d , N-1 : %d",abs(minus),N-1);
        exit(0);
    }
    
    for(int i = 2; i < N; i++){
        minus = abs(minus - num[i-2]) - num[i];
        if(0 < abs(minus) && abs(minus) <= N-1){
            cnt++;
        }else cnt--;
    }
    
    if(cnt == N-1){
        printf("YES");
    }else{
        printf("NO");
    }
    return 0;
    */
}
