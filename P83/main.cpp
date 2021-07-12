//복면산
#include<stdio.h>
//   S E N D
// + M O R E
// = M O N E Y
//각 문자가 어떤 수를 가지고 있어야 위의 공식이 성립되는가

//S E N D M O R Y
//0 1 2 3 4 5 6 7
//위와 같이 배열의 인덱스가 각 문자를 가리키고 있다고 가정한다.
//DFS를 이용하여 8개의 가지가 뻗어나간다고 생각한다.
//그러면 처음에는 각 문자가 0 1 2 3 4 5 6 7을 갖고 있는다(각 문자는 0부터 9까지의 수를 가질 수 있다.)
//만약 공식이 성립되지 않는다면
//0 1 2 3 4 5 6 8로 for문의 i가 하나 증가한다.
//0 1 2 3 4 5 6 9까지 for문이 다 끝나면 DFS(6)으로 돌아가서
//0 1 2 3 4 5 7 8로 DFS(6)의 for문이 돌아간다.
//이렇게하면 모든 문자에 대한 값들이 하나씩 바뀌면서 공식이 성립될떄까지 찾아나간다.
using namespace std;
 
int a[10], ch[10];
 
int send() {
    return a[0]*1000+a[1]*100+a[2]*10+a[3];
}
 
int more() {
    return a[4]*1000+a[5]*100+a[6]*10+a[1];
}
 
int money() {
    return a[4]*10000+a[5]*1000+a[2]*100+a[1]*10+a[7];
}
 
void DFS(int L) {
    if(L==8) {
        if(send()+more()==money()){
            if(a[0] == 0 || a[4] == 0) return;
            printf("  %d %d %d %d\n", a[0], a[1], a[2], a[3]);
            printf("+ %d %d %d %d\n", a[4], a[5], a[6], a[1]);
            printf("---------\n");
            printf("%d %d %d %d %d\n", a[4], a[5], a[2], a[1], a[7]);
        }
    }
    else {
        for(int i=0; i<10; i++) {
            if(ch[i]==0) {
                a[L]=i;
                ch[i]=1;
                DFS(L+1);
                ch[i]=0;
            }
        }
    }
}
int main() {
    DFS(0);
 
    return 0;
}
