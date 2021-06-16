#include <iostream>
#include <stdio.h>
using namespace std;
int main() {
    char str[51];
    int i, res = 0, cnt=0;
    
    scanf("%s",str);
    
    for(i = 0; i < str[i] != '\0'; i++){ //연산 줄여줌
        if(str[i] >= 48 && str[i] <= 57){
            res = res * 10 + (str[i]-48); //첫번째 res는 0임
        }
    }
    printf("%d\n", res);
    
    for(i = 1; i <= res; i++){
        if(res % i == 0){
            cnt++;
        }
    }
    
    printf("%d\n",  cnt);
    
    return 0;
}
