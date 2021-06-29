//못품
//소인수분해 응용한 문제는 배수가지고 장난치는 문제들임을 잊지말자
//소인수분해는 배수를 의심하자

//투포인터(세가지)를 배울 수 있는 문제다.

//세가지의 수를 비교하는 방법, 결과내는 방법도 익힐 수 있다.
//나의 약한 부분을 찔러주는 문제

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int N,i,p2=1,p3=1,p5=1, min = 2147000000;
    scanf("%d",&N);
    vector<int> UN(N+1);//Ugly Number
    
    UN[1] = 1;
    
    for(i = 2; i <= N; i++){
        
        //세 포인터 비교
        if(UN[p2]*2 < UN[p3]*3) min = UN[p2]*2;
        else min = UN[p3]*3;
        
        if(UN[p5]*5 < min) min = UN[p5]*5;
        
        //결과
        if(UN[p2]*2 == min) p2++;
        if(UN[p3]*3 == min) p3++;
        if(UN[p5]*5 == min) p5++;
        
        UN[i] = min;
    }
    printf("%d\n",UN[N]);
    
    return 0;
}
