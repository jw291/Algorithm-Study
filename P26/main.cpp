//스스로 해결!
//채점 필요
//입력한 순서대로가 아니라
//입력의 역순으로 모든 값들과 비교해야함
//따라서 저장해놨다가 비교하는 방법 밖에 없음
//브루트포스
//더 효율적으로 병합정렬을 사용하는 방법이 있음.
#include <iostream>
#include <vector>

using namespace std;
int main() {
    int N,i,j;
    
    scanf("%d",&N);
    
    vector<int> a(N);
    vector<int> b(N);
    
    for(i = 0; i < N; i++){
        scanf("%d",&a[i]);
        b[i] = i+1;
    }
    
    for(i = 1; i < N; i++){
        for(j = i-1; j >= 0; j--){
            if(a[i] > a[j]){
                b[i]--;
            }
        }
    }
    
    for(i = 0; i < N; i++){
        printf("%d",b[i]);
    }
    return 0;
}
