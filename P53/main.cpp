//stack을 이용해서
//넣은 순 역순으로 뽑아오기
#include <iostream>

using namespace std;

int stack[100], top = -1;

void push(int x){
    stack[++top] = x;
}

int pop(){
    return stack[top--];
}

int main() {
    int n, k;
    scanf("%d %d",&n,&k);
    char str[20] = "0123456789ABCDEF";
    
    while(n>0){
        push(n%k);
        n=n/k;
    }
    
    while (top != -1) {
        printf("%c", str[pop()]);
    }
    return 0;
}
