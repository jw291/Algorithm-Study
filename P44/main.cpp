//결정 알고리즘
//최대 값을 얻어야 함
//최소를 구하는 결정 알고리즘 문제는 그 이후 값도 가능하겠지 (lt = mid+1)로 최소화
//최대를 구하는 결정 알고리즘 문제는 그 이전 값도 가능하겠지 (rt = mid-1)로 최소화
//44번 강의 커뮤니티 보면 문제 리스트 있음
#include <stdio.h>
#include <algorithm>

using namespace std;
int N;

int Count(int size, int xi[]){//dvd개수
    int p = xi[1],i,cnt=1;
    for(i = 2; i <= N; i++){
        //뒤에 값들과 빼보다가
        //두 마굿간의 길이가 정답보다 크거나 같다면
        //말을 배치할 수 있음
        //그 자리에서 다음 마굿간과의 거리를 재서 크거나 같으면 말을 배치함
        //만약 정답이 3(mid == 3)이라면
        //마굿간 두 쌍의 거리가 둘 다 3보다 커야지
        //두 마굿간 중 가까운 마굿간 쌍의 거리가 3으로 설명할 수 있으므로
        if(xi[i] - p >= size){
            cnt++;
            p = xi[i];
        }
    }
    
    return cnt; //필요한 dvd개수 리턴
}

int main() {
    int C,lt=1,rt,mid,i,res;
    scanf("%d %d",&N,&C);
    
    int *xi = new int[N+1];
    
    for(i = 1; i <= N; i++){
        scanf("%d",&xi[i]);
    }
    
    sort(xi+1, xi + (N+1));
    
    rt = xi[N];
    
    while(lt <= rt){
        mid = (lt+rt)/2; //정답 하나 뽑아보기
        if(Count(mid,xi) >= C){//이거 정답 맞아? 넘겨줌
            // cnt가 3보다 작으면 말 3마리 배치를 못한다는 거니까 오답
            // 첫 반복때 Mid가 5인데 그럼 오답임.
            
            res = mid;
            lt = mid+1;
        }
        else rt = mid-1;
    }
    printf("%d\n",res);
    
    delete[] xi;
    
    return 0;
}
