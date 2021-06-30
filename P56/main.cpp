//재귀는 스택구조로 운영된다.
//호출된 자기자신이 스택구조로 쌓이면서
//자기가 실행했던 줄을 저장해놓고 나중에 그 다음줄을 실행한다.

//스택이 존재함
//함수가 호출되면 본인의 호출정보를 스택프레임이라고함
//스택에 본인의 호출정보를 기록한 그 것을 스택프레임이라고함(그 함수의 스택프레임이다.)

//메인이 호출되면 스택메모리에 제일 먼저 메인의 스택프레임(메인함수의 정보, 복귀 주소)이 쌓이게된다.
//그러다가 재귀를 만나면 스택에 잠시 머물러 있고 재귀 함수의 스택프레임이 저장된다.
//그럼 또 그 재귀함수의 매개변수,지역변수,복귀주소가 저장이 된다.
//여기서 D(2)의 스택프레임의 복귀주소는 D(3)의 9번째줄을 저장하고 있음
//자기 자신의 할일이 끝나면 D(3) 9번 라인으로 가겠다라고 하는거
//계속 스택에 스택프레임이 쌓이는데, 스택에 공간이 더이상 없으면 stackoverflow
#include <iostream>
#include <algorithm>

void recur(int x){
    if(x == 0) return; //원하는 종료지점에 멈춰라
    else{
        //prinf("%d",x); 3 2 1
        recur(x-1);
        printf("%d ", x);// 1 2 3
     }
}

int main() {
    int n;
    scanf("%d",&n);
    recur(n);
    return 0;
}
