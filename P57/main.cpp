#include <iostream>

void recur(int x){
    
    if(x == 0) return;
    
    recur(x/2);
    printf("%d",x % 2);
}

int main() {
    int N;
    scanf("%d",&N);
    
    recur(N);
    return 0;
}
