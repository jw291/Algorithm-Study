//dfs
//전위 : 위에서 시작
//중위 : 중간(부모)을 들림
//후위 : 아래부터 다 찍고 부모 들림
#include <iostream>

void D(int v){
    //구성을 하는게 중요함. D(1)-D(4)이렇게 여기서 이 1,4를 이용해서 실제 하는 일을 만들기
    if(v > 7) return;
    else{
        //printf("%d",v); 전위, 자기 일을 먼저 하고 왼쪽 오른쪽으로 간다.
        D(v*2);//왼쪽 구성
        //printf("%d",v); 중위, 왼쪽 일을 끝내고 자기 일을 한다음 오른쪽으로 간다.
        D(v*2+1);//오른쪽 구성
        //printf("%d",v); 후위, 왼쪽 오른쪽 일을 끝내고 자기 일을 한다.
    }
}

int main(int argc, const char * argv[]) {
    D(1);
    return 0;
}
