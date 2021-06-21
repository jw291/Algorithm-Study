//스스로 해결!
//지금까지는 입력한 순서대로 비교해줬으면 됐는데
//이 문제는 이전에 입력했던 값도 함께 비교해줘야해서
//for문이 두번쓰임
//하지만 온도의 최대값 문제처럼 공식화해서 풀 수도 있는데
//이건 딱봐도 공식화관련 문제가 아니다.
#include <iostream>
#include <vector>

using namespace std;
int main() {
    int N,i,j = 0,cnt=1;
    scanf("%d",&N);
    vector<int> a(N);
    vector<int> b(N);
    //b.assign(N, 1);
    
    for (i = 0; i < N; i++) {
        scanf("%d",&a[i]);
        b[i] = 1; // assign할 필요 없네ㅋㅋ
    }
    
    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            if(a[i] < a[j]){
                b[i]++;
            }
        }
    }
    
    for(i = 0; i < N; i++){
        printf("%d ",b[i]);
    }
    return 0;
}
